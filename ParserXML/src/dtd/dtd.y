%{
using namespace std;



#include <stack>
#include <list>
#include <vector>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "dtd.h"

#include "seq_validator.hpp"
#include "dtd_validator.hpp"
#include "data_validator.hpp"

#include "dtd_element.hpp"
#include "multiple_validator.hpp"
#include "xmlparse.h"
#include "alt_validator.hpp"

#include "empty_validator.hpp"
#include "any_validator.hpp"
#include "xml_element_validator.hpp"

#include "dtd.tab.h"


void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);


extern xml::Document* document_;


%}

%union { 
   char *s;
   xml::DtdValidator* v;
   std::vector<xml::DtdValidator* > * lv;
   xml::cardinality_t c;
   xml::MultipleValidator * mv;
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
%type <v> item children att_type contenu sequence_ou_choix
%type <lv> liste_sequence liste_choix
%type <c> cardinalite
%type <mv> sequence choix
%%

main: dtd
    ;

dtd: dtd ATTLIST NAME 
     att_definition CLOSE
   | dtd element
   | /* empty */
   ;

element:
	ELEMENT NAME contenu CLOSE
{
cerr << document_->doctype() << endl;
	/* nouvel element DTD a ajouter à la liste des element DTD du doctype */
	xml::DtdElement * elt = document_->doctype()->element($2);
	document_->doctype()->addElement(elt);
	
	// affecter a elt le validator
	elt->setValidator($3);
}
;

contenu
: EMPTY 
{
	$$ = new xml::EmptyValidator();
}
| ANY 
{
	$$ = new xml::AnyValidator();
}
| children
{
	$$ = $1;
}
//| /* vide */
;

children
: sequence_ou_choix cardinalite
{
	xml::DtdValidator * v = $1;
	
	// ajout cardinalite a la sequence ou choix
	v->setCardinality($2);
	
	$$ = v;
}
;

sequence_ou_choix
: sequence 
{
	$$ = $1;
}
| choix
{
 	$$ = $1;
} 
;

sequence
: OPENPAR liste_sequence CLOSEPAR
{
cerr << "sequence" << endl;

   // construction de la liste des items de la sequence terminee
   // => construction d'un SeqValidator
   xml::MultipleValidator * seqValidator = new xml::SeqValidator();
   
   // recuperation de la liste des items
   vector<xml::DtdValidator*> * l = $2;
   
   // ajout des validators fils dans seqValidator
   vector<xml::DtdValidator*>::iterator validator_it = l->begin();
   vector<xml::DtdValidator*>::iterator validator_it_end = l->end();

   while(validator_it != validator_it_end) {
   		seqValidator->pushValidator(*validator_it);
   		validator_it++;
   }
   
   // nettoyage liste items
   l->clear();
   delete l;
   
   // passe seqValidator
   $$ = seqValidator;
}
;

liste_sequence
: item 
{
     cerr << "liste_sequence FIRST" << endl;
	// 1er item de la sequence
	// allocation d'une liste d'item pour stocker tous les item de la sequence
	vector<xml::DtdValidator*> * l = new  vector<xml::DtdValidator*>;
	
	// ajout de l'item
	l->push_back($1);
	
	// passe liste
 	$$ = l;
}
| liste_sequence COMMA item 
{
	// recuperation de la liste des items en construction
	vector<xml::DtdValidator*> * l = $1;
	// un autre item dans la sequence a ete trouve, on l'ajoute a la liste des items 
	l->push_back($3);
	// on passe la liste au suivant
	$$ = l;
}
;

cardinalite
: QMARK 
{ 
	$$ = xml::_0_1; 
}
| PLUS  
{ 
	$$ = xml::_1_N; 
}
| AST 
{
	$$ = xml::_0_N; 
}
| /* */ 
{
	$$ = xml::_1_1;
}
;

item
: NAME cardinalite 
{
  // creation d'un xml element validator
  xml::XmlElementValidator * xmlValidator = new xml::XmlElementValidator($1);
  xmlValidator->setCardinality($2);
  
  $$ = xmlValidator;
}
| att_type
{
  	$$ = $1;
}
| children
{
  	$$ = $1;
}
;

choix
: OPENPAR liste_choix CLOSEPAR
{
cerr << "choix" << endl;

   // construction de la liste des items du choix terminee
   // => construction d'un AltValidator
   xml::MultipleValidator * altValidator = new xml::AltValidator();
   
   // recuperation de la liste des items
   vector<xml::DtdValidator*> * l = $2;
   
   // ajout des validators fils dans seqValidator
   vector<xml::DtdValidator*>::iterator validator_it = l->begin();
   vector<xml::DtdValidator*>::iterator validator_it_end = l->end();

   while(validator_it != validator_it_end) {
   		altValidator->pushValidator(*validator_it);
   		validator_it++;
   }
   
   // nettoyage liste items
   l->clear();
   delete l;
   
   // passe altValidator
   $$ = altValidator;
}
;

liste_choix
: item 
{
     cerr << "liste_choix FIRST" << endl;
	// 1er item du choix
	// allocation d'une liste d'item pour stocker tous les item du choix
	vector<xml::DtdValidator*> * l = new  vector<xml::DtdValidator*>;
	
	// ajout de l'item
	l->push_back($1);
	
	// passe liste
 	$$ = l;
}
| liste_choix PIPE item 
{
	// recuperation de la liste des items en construction
	vector<xml::DtdValidator*> * l = $1;
	// un autre item dans la liste a ete trouve, on l'ajoute a la liste des items 
	l->push_back($3);
	// on passe la liste au suivant
	$$ = l;
}
;

att_definition
: att_definition attribut
| /* empty */
;

attribut
: NAME att_type defaut_declaration
;

att_type
: CDATA
{
	xml::DataValidator * v = new xml::DataValidator();
	$$ = v;
}
| PCDATA
{
cerr << "PCDATA" << endl;
	// creation d'un validateur PCData
	xml::DataValidator * v = new xml::DataValidator();
	$$ = v;
}
| TOKENTYPE
{
	cerr << "TOKENTYPE non implemte" << endl;
}
| type_enumere
{
	cerr << "type_enumere non implemte" << endl;
}
;

type_enumere
: OPENPAR liste_enum_plus CLOSEPAR
;

liste_enum_plus
: liste_enum PIPE item_enum
;

liste_enum
: item_enum
| liste_enum PIPE item_enum
;

item_enum
: NAME
;

defaut_declaration
: DECLARATION
| STRING
| FIXED STRING
;
%%
int parse_dtd()
{
  int err;
// Compilation conditionelle pour la sortie de debug.
#ifdef DEBUG
  dtddebug = 0;
#endif
  err = dtdparse();
  if (err != 0) 
	printf("DTD file : parse ended with %d error(s)\n", err);
  else  printf("DTD file : parse ended with sucess\n");
  return err;
}

int main_dtd(int argc, char* argv[])
{
	return parse_dtd();
}

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


