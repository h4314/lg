/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DOCUMENT_H
#define XML_DOCUMENT_H

#include <istream>

#include "element.hpp"
#include "doctype.hpp"

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
     * @brief Constructeur d'un objet Document
     * @param instream Flux d'entrée
     */
    Document(std::istream instream);

    /**
     * @brief Lance l'analyse du fichier xml.
     * Les erreurs sont affichées sur la sortie d'erreur.
     * TODO vérifier.
     */
    void parse();

    /**
     * @brief Donne l'élément racine du document XML
     */
    inline Element& root() const {
      return _xmlElement;
    }

    /**
     * @brief Identifie la racine du document XML
     */
    void setRoot(Element& root);

    /**
     * @brief Donne le doctype du fichier
     * Note : on suppose par simplification qu'un document XML n'est associé
     * qu'à une seule DTD, définie dans un autre document.
     */
    inline Doctype& doctype() const {
      return _doctype;
    }

    /**
     * @brief identifie le doctype du fichier.
     */
    void setDoctype(Doctype& doctype);

  private:
    /** flux de lecture du document XML. */
    std::istream _instream;

    /** element racine */
    Element& _xmlElement;

    /** doctype du fichier */
    Doctype* _doctype;
};

}

#endif

