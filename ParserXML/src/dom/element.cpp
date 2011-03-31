/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "common.hpp"
#include "element.hpp"
#include "attribute.hpp"

using namespace std;

namespace xml {

Element::Element(Element* parent, const std::string& name) :
  Node(parent), _name(name), _children(), _attributes() {
//    DBG_STREAM << "Creating Element: " << name << endl;
//    DBG_STREAM << "Parent Element: " << (void*)parent << endl;
//    DBG_STREAM << "Element: " << (void*)this<< endl;
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
  DBG_STREAM << "<" << name();

  AttributeList::iterator ai = _attributes.begin();
  AttributeList::iterator ae = _attributes.end();
  for(;ai != ae;ai++)
  {
    (*ai)->display();
  }

  DBG_STREAM << ">" << endl;

  NodeList::iterator ni = _children.begin();
  NodeList::iterator ne = _children.end();
  for(;ni != ne;ni++)
  {
    (*ni)->display();
  }

  DBG_STREAM << "</" << name() << ">" << endl;
}


}

