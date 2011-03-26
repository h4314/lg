/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#ifndef XML_DTD_MULTIPLE_VALIDATOR_H
#define XML_DTD_MULTIPLE_VALIDATOR_H

#include "dtd_validator.hpp"

#include <list>

namespace xml {

/**
 * @brief Classe abstraite factorisant les ensembles de noeuds (SEQ, ALT)
 */
class MultipleValidator : public DtdValidator
{
  public:
    /**
     * @see DtdValidator::valid()
     */
    virtual bool valid(NodeList::iterator* cursor, NodeList::iterator& end) = 0;

    /**
     * @brief ajoute un validateur à la liste
     * @param validator validateur à ajouter
     */
    void pushValidator(DtdValidator& validator);

  private:
    /** Suite de validateurs */
    std::list<DtdValidator> _validators;
};

}

#endif

