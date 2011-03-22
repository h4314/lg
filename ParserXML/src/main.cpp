#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

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
	doc.root();
  // A toi de jouer !
  doc.parse();



 fclose(f);
  return 0;
}
