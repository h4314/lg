/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "dtd_validator.hpp"
#include <iostream>

using namespace std;

namespace xml {

// TODO Gérer cardinalité avec enum
DtdValidator::DtdValidator(): _cardinality(1) {
}

void DtdValidator::setCardinality(int cardinality) {
  _cardinality = cardinality;
}

}

