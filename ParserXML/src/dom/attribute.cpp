/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include <iostream>
#include "attribute.hpp"

using namespace std;

namespace xml {

Attribute::Attribute(std::string name, std::string value): _name(name), _value(value) {
};

void Attribute::setName(std::string name) {
  _name = name;
}

void Attribute::setValue(std::string value) {
  _value = value;
}

void Attribute::display()
{
  cerr << "Attr:" << _name << ":" << _value << endl;
}

}

