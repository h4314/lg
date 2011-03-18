/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "element.hpp"

using namespace std;

namespace xml {

Element::Element() : Node(), Element(string("")) {
}

Element::Element(string name) :
  Node(), _name(name), _children(), _attributes(), _cardinalityChildren() {
}

int Element::appendChild(Node& newChild) {
  _children.push_back(&newChild);
  return _children.size();
}

int Element::addAttribute(Attribute& newAttribute) {
  _attributes.push_back(newAttribute);
}

}

