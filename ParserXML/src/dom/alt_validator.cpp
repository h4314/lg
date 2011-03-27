/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "alt_validator.hpp"

#include <list>

using namespace std;

namespace xml {

/**
 * On va vérifier qu'au moins un validateur "fils" est conforme. On s'arrête dès
 * qu'un élément est validé.
 * Le comportement est ici assez proche du "||".
 */
bool AltValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end)
{
  bool result(false);
  bool must_continue(false);

  list<Validator*>::iterator validator_it = _validators.begin();
  list<Validator*>::iterator validator_it_end = _validators.end();

  do {
    while(validator_it != validator_it_end)
    {
      if(validator_it->valid(cursor, end)) {
        result = true;
        ++(*cursor);

        if(_cardinality == _0_N || _cardinality == _1_N) {
          must_continue = true;
        }
        break;
      }

      ++validator_it;
    }

    // On est allé au bout sans s'interrompre = on a rien validé
    if(validator_it == validator_it_end) {
      must_continue = false;
      if(_cardinality == _0_1 || _cardinality == _0_N) {
        result = true;
      }
    }

    if(must_continue) {
      validator_it = _validators.begin();
    }
  }
  while(must_continue);

  return result;
}

}

