#include <fstream>
#include <cstdlib>
#include <cstring>

#include "document.hpp"

using namespace std;
using namespace xml;


/**
 * args : filename, or - for standard input
 *
 * no args means standard input too.
 */
int main(int argc, char** argv)
{
	istream* is = 0;

  if(argc >= 2 && strcmp(argv[1], "-"))
	{
		is = new ifstream(argv[1], ios_base::in);
	}
	else
	{
		is = &cin;
	}
  if(is->bad())
  {
    cerr << "Error opening file" << endl;
    exit(EXIT_FAILURE);
  }

  Document doc(is);
  // A toi de jouer !
	
  if(argc >= 2 && strcmp(argv[1], "-"))
	{
		delete is;
	}
  return 0;
}
