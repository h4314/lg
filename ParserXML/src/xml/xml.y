%{

using namespace std;
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "commun.h"
#include "element.h"
#include "xml.tab.h"
#include "dtd.h"
#include "xmlparse.h"

int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);

/// Cette variable globale va recevoir le nom de la DTD, pour initier l'analyse
/// du fichier référencer dans le fichier xml.
std::string dtd_name;

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
}

%token EQ SLASH CLOSE END CLOSESPECIAL DOCTYPE
%token <s> ENCODING VALUE DATA COMMENT NAME NSNAME
%token <en> NSSTART START STARTSPECIAL

%%

document
 : declarations element misc_seq_opt 
 ;
misc_seq_opt
 : misc_seq_opt misc
 | /*empty*/
 ;
misc
 : COMMENT		
 ;

declarations
 : declaration
 | /*empty*/
 ;
 
declaration
 /* Déclaration de la DTD trouvée : le 4e token est le chemin de la DTD.
  * Il faut maintenant valider la DTD à l'aide de la fonction handle_dtd
  * L'analyse du document XML continue après l'analyse de la DTD.
  */
 : DOCTYPE NAME NAME VALUE CLOSE { dtd_name = $4; handle_dtd(dtd_name); document->setDoctype(new Doctype(dtd_name));  }
 ;

element
 : start attributes empty_or_content 
 | start empty_or_content 
 ;

start
 : START		
 | NSSTART 	
 ;

empty_or_content
 : SLASH CLOSE	
 | close_content_and_end name_or_nsname_opt CLOSE 
 ;

name_or_nsname_opt
 : NAME  {
 Element * node = new Element($1);
if(current == 0) { document->setRoot(node); }
current->appendChild(node); current = node; 
}
 | NSNAME {
 Element * node = new Element($1);
if(current == 0) { document->setRoot(node); }
current->appendChild(node); current = node; 
}
 | /* empty */
 ;
close_content_and_end
 : CLOSE content END { current = current->parent(); }
 ;
content 
 : content DATA	{ TextNode * node = new TextNode($2); current->appendChild(node); current = node; }		
 | content misc
 | content element
 | /*empty*/
 ;

attributes
: attributes attribut 
| attribut
;

attribut
: NAME EQ VALUE { current->addAttribute(new Attribute($1, $3));}
;
%%

int main(int argc, char **argv)
{
  int err;

  // parsing du xml en utilisant le parser généré par Bison
  err = xmlparse();
  if (err != 0) printf("XML file : parse ended with %d error(s)\n", err);
  	else  printf("XML file : parse ended with sucess\n");

  return 0;
}

// Cette fonction permet de pouvoir parser plusieurs fichiers
int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

