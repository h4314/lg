%option 8bit nodefault

%{
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "dtd.tab.h"

static char* skipSpace(char *s) {
  char *buf;
  int i,lastnonspace;
  for (buf=s;isspace(*buf);buf++) ;
  for (i=0,lastnonspace=0;buf[i];i++) {
     if (!isspace(buf[i]))
        lastnonspace = i;
  }
  buf[lastnonspace+1] = '\0';
  return strdup(buf);
}
  
/* affecte la valeur de la chaine de caractère et renvoie le token */
#define stringreturn(tokenval) dtdlval.s=skipSpace(dtdtext);return(tokenval)

%}
%option noyywrap

nl		(\r\n|\r|\n)
ws		[ \t\r\n]+
open		{nl}?"<"
close		">"{nl}?
openpar "("
closepar ")"
comma ","
pipe "|"
esc		"&#"[0-9]+";"|"&#x"[0-9a-fA-F]+";"
namestart	[A-Za-z\200-\377_]
namechar	[A-Za-z\200-\377_0-9.-]
tokentype "ID"|"IDREF"|"IDREFS"|"ENTITY"|"ENTITIES"|"NMTOKEN"|"NMTOKENS"
name		{namestart}{namechar}*
comment		{open}"!--"([^-]|"-"[^-])*"--"{close}
string		\"([^"&]|{esc})*\"|\'([^'&]|{esc})*\'
element {open}"!ELEMENT"{ws}
attlist {open}"!ATTLIST"{ws}
declaration "#"("REQUIRED"|"IMPLIED"){ws}?
fixed "#FIXED"{ws}
pcdata "#PCDATA"{ws}?
cdata "CDATA"{ws}?
qmark "?"
ast "*"
plus "+"
empty "EMPTY"
any "ANY"

%s INSIDE

/* 
   INITIAL : en dehors d'un bloc ELEMENT ou ATTLIST
   INSIDE : dans un bloc ELEMENT ou ATTLIST
*/

%%

<INITIAL>{ws}		            { /* skip */}
<INITIAL>{element}            {printf("%s",dtdtext); BEGIN(INSIDE); return ELEMENT; }
<INITIAL>{attlist}            {printf("%s",dtdtext); BEGIN(INSIDE); return ATTLIST; }
<INSIDE>{close}               {printf("%s",dtdtext); BEGIN(INITIAL); return CLOSE; }
<INSIDE>{openpar}             {printf("%s",dtdtext); return OPENPAR; }
<INSIDE>{closepar}{ws}?       {printf("%s",dtdtext); return CLOSEPAR; }
<INSIDE>{comma}{ws}?          {printf("%s",dtdtext); return COMMA; }
<INSIDE>{pipe}{ws}?           {printf("%s",dtdtext); return PIPE; }
<INSIDE>{declaration}         {printf("%s",dtdtext); stringreturn(DECLARATION); }
<INSIDE>{fixed}               {printf("%s",dtdtext); return FIXED; }
<INSIDE>{ast}                 {printf("%s",dtdtext); return AST ; }
<INSIDE>{qmark}               {printf("%s",dtdtext); return QMARK ; }
<INSIDE>{plus}                {printf("%s",dtdtext); return PLUS ; }
<INSIDE>{empty}               {printf("%s",dtdtext); return EMPTY; }
<INSIDE>{any}                 {printf("%s",dtdtext); return ANY; }
<INSIDE>{pcdata}              {printf("%s",dtdtext); return PCDATA; }
<INSIDE>{cdata}               {printf("%s",dtdtext); return CDATA; }
<INSIDE>{string}              {printf("%s",dtdtext); stringreturn(STRING); }
<INSIDE>{tokentype}{ws}?      {printf("%s",dtdtext); stringreturn(TOKENTYPE); }
<INSIDE>{name}{ws}?           {printf("%s",dtdtext); stringreturn(NAME); }
{comment}		               {printf("%s",dtdtext); /* skip comments stringreturn(COMMENT); */ }

.			{printf("%s",dtdtext);fprintf(stderr, "!ERROR(%c)\n", *dtdtext);}
{nl}			{printf("%s",dtdtext);/* skip, must be an extra one at EOF */;}
