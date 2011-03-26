/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "data_validator.hpp"
#include "data.hpp"

using namespace std;

namespace xml {

/**
 * Data est vrai si on pointe une séquence de noeuds Data.
 */
DataValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end) {
  bool result(true);
  bool must_continue(true);

  do {
    if(dynamic_cast<Data*>(*cursor)) {
      // On en a trouvé 1, c'est bon
      result = true;
      // On avance donc le curseur
      ++(*it);
    }
    else {
      // Element non validé, on arrête de chercher
      must_continue = false;

      // Pouvait-on en avoir 0 ?
      if(!result && (_cardinality == _0_1 || _cardinality == _0_N)) {
        result = true;
      }
    }
  }
  // On peut valider plusieurs noeuds texte (même si c'est stupide, et sans
  // respect de la cardinalité).
  while(must_continue);

  return result;
}

}

