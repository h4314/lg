/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_DATA_H
#define XML_DTD_DATA_H

#include <istream>
#include <string>

#include "dtd_element.hpp"

namespace xml {

/**
 * @brief La classe représente le doctype d'un DTD
 */
class Data: public DtdElement
{
  public:
    /**
     * @brief Le constructeur
     */
    Data();

    /**
     * @brief Valide un élément XML d'après sa définition dans la DTD
     * @param elt L'élément à valider
     */
    virtual bool valid(Element* elt);

  private:
};

}

#endif

