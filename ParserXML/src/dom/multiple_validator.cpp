/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "multiple_validator.hpp"

using namespace std;

namespace xml {

void MultipleValidator::pushValidator(DtdValidator* validator) {
  _validators.push_back(validator);
}

}

