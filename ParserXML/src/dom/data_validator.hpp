/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_DATA_VALIDATOR_H
#define XML_DTD_DATA_VALIDATOR_H

#include "dtd_validator.hpp"

namespace xml {

/**
 * @brief valide des noeuds texte.
 */
class DataValidator : public DtdValidator
{
  public:
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor NodeList::iterator& end);
};

}

#endif

