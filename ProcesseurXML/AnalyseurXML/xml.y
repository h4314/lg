%{

using namespace std;
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "commun.h"
#include "xml.tab.h"
#include "../AnalyseurDTD/dtd.h"
#include "xmlparse.h"

int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);
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
 : DOCTYPE NAME NAME VALUE CLOSE { dtd_name = $4; handle_dtd(dtd_name);  }
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
 : NAME     
 | NSNAME  
 | /* empty */
 ;
close_content_and_end
 : CLOSE content END 
 ;
content 
 : content DATA		
 | content misc        
 | content element      
 | /*empty*/         
 ;

attributes
: attributes attribut
| attribut
;

attribut
: NAME EQ VALUE
;
%%

int main(int argc, char **argv)
{
  int err;

  err = xmlparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  	else  printf("Parse ended with sucess\n");

   std::cout << dtd_name << std::endl;

  return 0;
}
int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

