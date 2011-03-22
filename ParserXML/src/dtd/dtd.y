%{
using namespace std;
#include <stack>
#include <list>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "dtd.h"


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
	ELEMENT NAME contenu CLOSE;

contenu
: EMPTY
| ANY
| children
| /* vide */
;

children
: sequence_ou_choix cardinalite
;

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
: QMARK
| PLUS
| AST
| /* vide */
;

item
: NAME cardinalite
| att_type
| children
;

choix
: OPENPAR liste_choix_plus CLOSEPAR;

liste_choix_plus
: liste_choix  PIPE item
;

liste_choix
: liste_choix PIPE item | item
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


