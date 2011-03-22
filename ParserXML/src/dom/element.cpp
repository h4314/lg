/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "element.hpp"
#include <iostream>

using namespace std;

namespace xml {

Element::Element(Element* parent, const std::string& name) :
  Node(parent), _name(name), _children(), _attributes(), _cardinalityChildren() {
    cerr << "Creating Element: " << name << endl;
}

int Element::appendChild(Node* newChild) {
  _children.push_back(newChild);
  return _children.size();
}

int Element::addAttribute(Attribute* newAttribute) {
  _attributes.push_back(newAttribute);
	return _attributes.size();
}


void Element::display()
{
  cerr << "I am an Element: " << name() << endl;
}


}

