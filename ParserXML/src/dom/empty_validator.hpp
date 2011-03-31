/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_EMPTY_VALIDATOR_H
#define XML_DTD_EMPTY_VALIDATOR_H

#include "dtd_validator.hpp"
#include "node.hpp"

namespace xml {

/**
 * @brief EmptyValidator valide une séquence vide.
 */
class EmptyValidator : public DtdValidator
{
  public:
    virtual ~EmptyValidator();
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end) ;
};

}

#endif

