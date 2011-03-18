/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "attribute.hpp"

using namespace std;

namespace xml {

Attribute::Attribute(): Attribute(string(""), string("")) {
}

Attribute::Attribute(string name, stirng value): _name(name), _value(value) {
};

void Attribute::setName(string name) {
  _name = name;
}

void Attribute::setValue(string value) {
  _value = value;
}

}

