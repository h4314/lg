/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "dtd_validator.hpp"
#include <iostream>

using namespace std;

namespace xml {

DtdValidator::DtdValidator(): _cardinality(_1_1) {
}

void DtdValidator::setCardinality(_cardinality_t cardinality) {
  _cardinality = cardinality;
}

}

