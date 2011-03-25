/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_ELEMENT_H
#define XML_DTD_ELEMENT_H

#include <istream>
#include <string>

#include "element.hpp"

namespace xml {

/**
 * @brief La classe représente le doctype d'un DTD
 */
class DtdElement
{
  public:
    /**
     * @brief Le constructeur
     */
    DtdElement();

    /**
     * @brief Valide un élément XML d'après sa définition dans la DTD
     * @param elt L'élément à valider
     */
    virtual bool valid(Element* elt) = 0;

  private:
};

}

#endif

