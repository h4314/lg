/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_ALT_VALIDATOR_H
#define XML_DTD_ALT_VALIDATOR_H

#include "multiple_validator.hpp"

namespace xml {

/**
 * @brief Classe validant une séquence d'alternatives comme
 * ([Validator]|[Validator]). Un validateur doit être vérifié pour qu'on
 * considère la séquence comme valide.
 */
class AltValidator : public MultipleValidator
{
  public:
   virtual ~AltValidator();
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end);

};

}

#endif

