/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_EMPTY_VALIDATOR_H
#define XML_DTD_EMPTY_VALIDATOR_H

#include "dtd_validator.hpp"

namespace xml {

/**
 * @brief EmptyValidator valide une séquence vide.
 */
class EmptyValidator : public DtdValidator
{
  public:
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end);
};

}

#endif

