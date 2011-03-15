#include "xmlparse.h"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <errno.h>
#include "../AnalyseurDTD/dtd.h"

extern "C" FILE* dtdin;

void handle_dtd(const std::string& filename)
{
	FILE* fid;
	int err;
	fid = fopen(filename.c_str(), "r");
	if( ! fid)
	{
		perror("ouverture fichier dtd");
		exit(EXIT_FAILURE);
	}

	dtdin = fid;
	err = parse_dtd();
	fclose(fid);
}
