/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_SEQ_VALIDATOR_H
#define XML_DTD_SEQ_VALIDATOR_H

#include "multiple_validator.hpp"

namespace xml {

/**
 * @brief Classe validant une séquence d'éléments comme ([Validateur],
 * [Validateur]). L'intégralité de la séquence doit être validée.
 */
class SeqValidator : public MultipleValidator
{
  public:
    ~SeqValidator();
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end);
};

}

#endif

