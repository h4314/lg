/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "empty_validator.hpp"

using namespace std;

namespace xml {

EmptyValidator::~EmptyValidator()
{}

/**
 * Empty est vrai si on est à la fin de la séquence.
 */
bool EmptyValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end) {
  return (*cursor == end);
}

}

