/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "any_validator.hpp"

using namespace std;

namespace xml {

/**
 * Le curseur est placé à la fin (toute la séquence est validée).
 */
bool AnyValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end) {
  *cursor = end;
  return true;
}

}

