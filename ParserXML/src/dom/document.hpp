/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DOCUMENT_H
#define XML_DOCUMENT_H

#include <iostream>
#include <cstdio>

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
    Document(FILE* f = stdin);

    /**
     * @brief Lance l'analyse du fichier xml.
     * Les erreurs sont affichées sur la sortie d'erreur.
     */
    bool parse();

    /**
     * @brief valide l'arbre XML d'après la DTD
     * @return Retourne vrai si l'arbre est validé, faux sinon.
     * Si aucune DTD n'est renseignée, la méthode retourne faux.
     */
    bool validateWithDtd() const;

    /**
     * @brief Donne l'élément racine du document XML
     */
    inline Element* root() const {
      return _xmlElement;
    }

    /**
     * @brief Identifie la racine du document XML
     */
    void setRoot(Element* root);

    /**
     * @brief Donne le doctype du fichier
     * Note : on suppose par simplification qu'un document XML n'est associé
     * qu'à une seule DTD, définie dans un autre document.
     */
    inline Doctype* doctype() const {
      return _doctype;
    }

    /**
     * @brief identifie le doctype du fichier.
     */
    void setDoctype(Doctype* doctype);

  private:
    /**
     * @brief Valide l'élement elt et tous ses descendants.
     * @param elt Pointeur sur l'élément à valider
     * @return Vrai si l'élément et tous ses descendants sont validés
     */
    bool _validateElementChildrenWithDtd(Element* elt) const;

    /** flux de lecture du document XML. */
    FILE* _f;

    /** element racine */
    Element* _xmlElement;

    /** doctype du fichier */
    Doctype* _doctype;
};

}

#endif

