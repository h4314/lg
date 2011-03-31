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

DtdValidator::~DtdValidator()
{

}

void DtdValidator::setCardinality(cardinality_t cardinality) {
  _cardinality = cardinality;
}

}

