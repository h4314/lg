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

xml::DtdElement * current_elt_ = 0;
stack<xml::MultipleValidator*> current_multi_;


void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);


%}

%union { 
   char *s;
   xml::DtdValidator* v;
   std::vector<xml::DtdValidator* > * ls;
   xml::cardinality_t c;
   xml::SeqValidator * sv;
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
%type <v> item children att_type
%type <ls> liste_sequence 
%type <c> cardinalite
%type <sv> sequence
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
	/* nouvel element DTD a ajouter à la liste des element DTD du doctype */
	xml::DtdElement * elt = document_->doctype()->element($2);
	document_->doctype()->addElement(elt);
	
	/* garde cet element comme courant */
	current_elt_ = elt;
}
;

contenu
: EMPTY {current_elt_->setValidator(new xml::EmptyValidator());}
| ANY {current_elt_->setValidator(new xml::AnyValidator());}
| children
| /* vide */
;

children
: sequence_ou_choix cardinalite;

sequence_ou_choix
: sequence 
| choix 
;

sequence
: OPENPAR liste_sequence CLOSEPAR
{
   // construction de la liste des items de la sequence terminee
   // => construction d'un SeqValidator
   xml::SeqValidator * seqValidator = new xml::SeqValidator();
   
   // recuperation de la liste des items
   vector<xml::DtdValidator*> * l = $2;
   
   // ajout des validators fils dans seqValidator
   vector<xml::DtdValidator*>::iterator validator_it = l->begin();
   vector<xml::DtdValidator*>::iterator validator_it_end = l->end();

   while(validator_it != validator_it_end) {
   		seqValidator->pushValidator(*validator_it);
   }
   
   // passe seqValidator
   $$ = seqValidator;
}
;

liste_sequence
: item 
{
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

	/* item trouvé dans une sequence ou un choix
  if(current_multi_.empty())
  {
    current_multi_.push(new xml::XmlElementValidator($1));
    current_multi_.top()->setCardinality($2);
  }
  else
  {
    current_multi_.top()->push(new xml::XmlElementValidator($1));
    current_multi_.top()->setCardinality($2);
  }
   */
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
: OPENPAR liste_choix_plus CLOSEPAR
{
	/* fin d'un choix, elimination du validator mulitple courant situe en top de la stack*/
	current_multi_.pop();
	/* le top de la stack est maintenant soit vide : pas de multiple validator en cours de parsage 
	   soit le top de la pile est le multiple validator du niveau du dessus
	*/
}
;

liste_choix_plus
: liste_choix  PIPE item
;

liste_choix
: liste_choix PIPE item 
{
	/* sequence rencontré */
	xml::AltValidator * v = new xml::AltValidator();
	/* defini ce validateur de choix comme le validateur multiple courant */
	current_multi_.push(v);
}
| item
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
| PCDATA
{
	// creation d'un validateur PCData
	xml::DataValidator * v = new xml::DataValidator();
	$$ = v;
}
| TOKENTYPE
| type_enumere
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


