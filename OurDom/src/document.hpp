/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DOCUMENT_H
#define XML_DOCUMENT_H

#include <istream>

namespace xml {

/**
 * @brief La classe Document représente un document XML.
 * Le document XML est analysé syntaxiquement et validé conformément à sa DTD.
 * Le document XML est lu depuis un flux.
 */
class Document
{
  public:
    /**
     * @brief Constructeur d'un objet élément
     * @param instream Flux d'entrée
     */
    Document(std::istream instream);

  protected:
  private:
    std::istream _instream;
};

}

#endif

