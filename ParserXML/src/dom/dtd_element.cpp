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

bool valid(const Element* const elt)
{
  bool result(false);

  // Validation du contenu du noeud
  NodeList::iterator cursor(elt->children().begin());
  // La validation est correcte si et seulement si le validateur répond vrai et
  // que tous les noeuds fils ont été analysés.
  // Par exemple (FOO*|BAR*|BAZ*) pourrait retourner vrai sans pour autant
  // valider tous les fils, ce qui est en fait une erreur.
  result = DtdValidator->valid(&cursor, elt->children().end()) &&
    cursor == elt->children()->end();

  if(result) {
    // On a validé les noeuds fils, on va vérifier les attributs
    AttributeList::iterator attr_it = elt.attributes().begin();
    AttributeList::iterator attr_it_end = elt.attributes().end();

    DtdAttributeList::iterator found;
    while(attr_it != attr_it_end) {
      found = _attributes.find(attr->name());

      if(found == _attributes.end()) {
        // On a pas trouvé l'attribut, c'est une erreur
        result = false;
        // Pas la peine d'aller plus loin
        break;
      }
    }
  }

  return result;
}

}

