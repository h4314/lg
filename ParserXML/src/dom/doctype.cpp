/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "doctype.hpp"

using namespace std;

namespace xml {

Doctype::Doctype(const std::string& name) :_name(name), _elements()
{}

/**
 * Parcours l'ensemble des éléments pour libérer la mémoire allouée.
 */
Doctype::~Doctype()
{
  DtdElementList::iterator it = _elements.begin();
  while(it != _elements.end()) {
    delete it->second;
    it++;
  }
}

DtdElement* Doctype::element(string name) {
  DtdElement* elt(0);
  DtdElementList::iterator q = _elements.find(name);
  if(q == _elements.end()) {
    elt = new DtdElement(name);
    _elements[name] = elt;
  }
  else {
    elt = q->second;
  }
  // TODO assert(elt != 0);
  return elt;
}

DtdElement* Doctype::element(const char* eltname) {
  return element(string(eltname));
}

void Doctype::addElement(DtdElement* element) {
  _elements[element->name()] = element;
}

}



