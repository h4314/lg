#include <string>
#include <cstdio>
#include <cstdlib>
#include <errno.h>
#include <iostream>
#include "dtd.h"
#include "xmlparse.h"

/// Flux d'entrée du parser pour la DTD, crée par Flex.
extern "C" FILE* dtdin;
extern "C" FILE* xmlin;

/**
 * @brief Gérer l'analyse d'un document DTD dont le chemin est passé en
 * paramètre.
 *
 * @param filename Le chemin (relatif ou absolu) vers un fichier DTD.
 */
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

  // On change le flux entrant pour l'analyse, de stdin vers le nouveau fichier
  // que l'on vient d'ouvrir.
  dtdin = fid;
  // Lancer l'analyse de la DTD.
  err = parse_dtd();
  fclose(fid);
}

bool parseXML(FILE* f, xml::Document * doc) {
  int err;

  document_ = doc;

  xmlin = f;
  // parsing du xml en utilisant le parser généré par Bison
  err = xmlparse();
  if (err != 0)
    printf("XML file : parse ended with %d error(s)\n", err);
  else
    printf("XML file : parse ended with sucess\n");

  return (err == 0);
}
