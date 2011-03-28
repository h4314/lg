#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "common.hpp"
#include "document.hpp"
#include "xmlparse.h"

using namespace std;
using namespace xml;


/**
 * args : filename, or - for standard input
 *
 * no args means standard input too.
 */
int main(int argc, char** argv)
{
	FILE* f;

  if(argc >= 2 && strcmp(argv[1], "-"))
	{
		f = fopen(argv[1], "r");
	}
	else
	{
		f = stdin;
	}
  if( ! f)
  {
    cerr << "Error opening file" << endl;
    exit(EXIT_FAILURE);
  }

  Document doc(f);
  // A toi de jouer !
  bool ret = doc.parse();

  // Retour de doc.parse() modifié pour qu'il retourne vrai si pas d'erreur
  if(ret)
    doc.root()->display();

  // Validation
  bool valid = doc.validateWithDtd();
  if(valid) {
    DBG_STREAM << "Valide selon la DTD" << endl;
  }
  else {
    DBG_STREAM << "Invalide selon la DTD" << endl;
  }

  fclose(f);
  DBG_STREAM << "ret: " << ret << endl;

  return ret; // pour le unit testing
}
