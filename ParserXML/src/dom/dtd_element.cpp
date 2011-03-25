/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "dtd_element.hpp"
#include "dtd_validator.hpp"
#include "node.hpp"

using namespace std;

namespace xml {

DtdElement::DtdElement(std::string& name): _name(name), _validator(0),
  _attributes()
{
}

void DtdElement::setValidator(DtdValidator* validator) {
  _validator = validator;
}

void DtdElement::addAttribute(std::string& attrname) {
  _attributes.insert(attrname);
}

bool valid(Element* elt)
{
  bool result(false);

  // Validation du contenu du noeud
  NodeList::iterator cursor(elt->children().begin());
  result = DtdValidator->valid(&cursor, elt->children().end());

  if(result) {
    // TODO Valider les attributs
  }

  return result;
}

}

