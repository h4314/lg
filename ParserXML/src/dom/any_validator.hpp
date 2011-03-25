/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_ANY_VALIDATOR_H
#define XML_DTD_ANY_VALIDATOR_H

#include "dtd_validator.hpp"

namespace xml {

/**
 * @brief AnyValidator valide toute séquence.
 */
class AnyValidator : public DtdValidator
{
  public:
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor NodeList::iterator& end);
};

}

#endif

