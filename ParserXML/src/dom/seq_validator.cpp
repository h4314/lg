/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "seq_validator.hpp"

#include <list>

using namespace std;

namespace xml {

/**
 * Pour chaque validateur fils, on vérifie que l'élément lui est conforme.
 * On s'arrête au premier échec.
 * Le comportement est ici assez proche du "&&".
 */
bool SeqValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end)
{
  bool result(true);
  bool must_continue(true);

  // Permet d'invalider un début de séquence supposé valide
  NodeList::iterator* begining = cursor;

  // Itérateur sur les validateurs
  list<Validator*>::iterator validator_it = _validators.begin();
  list<Validator*>::iterator validator_it_end = _validators.end();

  do {
    while(validator_it != validator_it_end) {
      // Pas besoin de faire avancer le curseur si l'élément est valide : le
      // validateur appelé l'a déjà fait
      // On a donc rien à faire si l'élément est validé
      if(!validator_it->valid(cursor, end))
      {
        // on invalide tout le début de séquence
        cursor = begining;

        // On pouvait en avoir "O"
        if(!result && (_cardinality == _0_1 || _cardinality == _0_N)) {
          result = true;
        }
        else {
          result = false;
        }

        // On ne continue pas à tester
        break;
      }
      ++validator_it;
    }

    // On est allé au bout, on se prépare à valider une nouvelle séquence
    // On peut répeter cette séquence ?
    if( validator_it == validator_it_end &&
        (_cardinality == _0_N || _cardinality == _1_N)
      )
    {
      validator_it = _validators.begin();
    }
    else {
        must_continue = false;
    }
  }
  // On recommence si la cardinalité le suggère
  while(must_continue);

  return result;
}

}

