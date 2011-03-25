/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "element.hpp"
#include "attribute.hpp"
#include <iostream>

using namespace std;

namespace xml {

Element::Element(Element* parent, const std::string& name) :
  Node(parent), _name(name), _children(), _attributes(), _cardinalityChildren() {
    cerr << "Creating Element: " << name << endl;
    cerr << "Parent Element: " << (void*)parent << endl;
    cerr << "Element: " << (void*)this<< endl;
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

  AttributeList::iterator ai = _attributes.begin();
  AttributeList::iterator ae = _attributes.end();
  cerr << "Attributes:" << endl;
  for(;ai != ae;ai++)
  {
    (*ai)->display();
  }

  std::vector<Node*>::iterator ni = _children.begin();
  std::vector<Node*>::iterator ne = _children.end();
  for(;ni != ne;ni++)
  {
    (*ni)->display();
  }
}


}

