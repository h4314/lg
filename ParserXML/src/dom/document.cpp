/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "document.hpp"
#include "xmlparse.h"
#include "dtd_element.hpp"
#include "common.hpp"

using namespace std;

namespace xml {

Document::Document(FILE* f):
  _f(f), _xmlElement(0), _doctype(0) {
  }

void Document::setRoot(Element* element) {
  _xmlElement = element;
}

void Document::setDoctype(Doctype* doctype) {
  _doctype = doctype;
}

bool Document::parse() {
  return parseXML(_f, this);
}

/**
 * On valide la racine (avec ses descendants)
 */
bool Document::validateWithDtd() const {
  if(_doctype == 0)
    return false;

  return _validateElementChildrenWithDtd(_xmlElement);
}

/**
 * On valide l'élément puis ses fils, l'appel étant récursif, on effectue en
 * fait un parcours d'une branche en profondeur, en traitant le noeud père
 * d'abord (ce qui est *potentiellement* un peu plus optimisé).
 */
bool Document::_validateElementChildrenWithDtd(Element* elt) const
{
  DtdElement* dtd_element = _doctype->element(elt->name());

  bool result(dtd_element->valid(elt));

  // L'élement est valide, on teste ses enfants
  if(result)
  {
    NodeList::const_iterator it = elt->children().begin();
    NodeList::const_iterator end = elt->children().end();
    Element* child(0);
    while(it != end) {
      child = dynamic_cast<Element*>(*it);
      if(child && !_validateElementChildrenWithDtd(child)) {
        result = false;
        break;
      }
      ++it;
    }
  }

  return result;
}

}

