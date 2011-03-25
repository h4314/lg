/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "empty_validator.hpp"

using namespace std;

namespace xml {

/**
 * Empty est vrai si on est à la fin de la séquence.
 */
EmptyValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end) {
  return (*cursor == end);
}

}

