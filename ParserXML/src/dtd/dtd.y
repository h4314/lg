%{
using namespace std;
#include <stack>
#include <list>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "dtd.h"

#include "dtd_element.hpp"
#include "multiple_validator.hpp"
#include "xmlparse.h"
#include "alt_validator.hpp"
#include "seq_validator.hpp"
#include "empty_validator.hpp"
#include "any_validator.hpp"
#include "xml_element_validator.hpp"

xml::DtdElement * current_elt_ = 0;
stack<xml::MultipleValidator*> current_multi_;


void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);
%}

%union { 
   char *s; 
   }

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> NAME TOKENTYPE DECLARATION STRING
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
;

liste_sequence
: item
| liste_sequence COMMA item
;

cardinalite
: QMARK { $$ = xml::_0_1; }
| PLUS  { $$ = xml::_1_N; }
| AST {$$ = xml::_0_N; }
| /* */ {$$ = xml::_1_1;}
;

item
: NAME cardinalite 
{
	/* item trouvé dans une sequence ou un choix */
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
}
| att_type
| children
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


