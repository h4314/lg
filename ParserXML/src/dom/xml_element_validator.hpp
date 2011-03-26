/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_XML_ELEMENT_VALIDATOR_H
#define XML_DTD_XML_ELEMENT_VALIDATOR_H

#include "dtd_validator.hpp"

#include <string>

namespace xml {

/**
 * @brief EmptyValidator valide une séquence vide.
 */
class XmlElementValidator : public DtdValidator
{
  public:
    /**
     * @brief constructeur
     * @param name Nom de la balise attendue
     */
    XmlElementValidator(std::string &name);

    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end);

  private:
    /** nom de la balise attendue */
    std::string _name;
};

}

#endif

