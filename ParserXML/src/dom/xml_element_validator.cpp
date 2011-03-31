/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "xml_element_validator.hpp"
#include "element.hpp"

using namespace std;

namespace xml {

  XmlElementValidator::XmlElementValidator(const std::string &name)
    : DtdValidator(), _name(name) {
  }


  XmlElementValidator::~XmlElementValidator() {

  }

  /**
   * On considère l'élément validé si, d'après la cardinalité souhaitée, une
   * série (de 0, 1 ou plus, etc) d'éléments de type xml::Element et dont le nom
   * correspond est trouvée.
   */
  bool XmlElementValidator::valid(NodeList::iterator* cursor, NodeList::iterator& end) {

    bool result(false);
    bool must_continue(true);

    do {
      Element* element = dynamic_cast<Element*>(**cursor);
      if(element && (_name == element->name())) {
        result = true;

        // Element validé : on avance le curseur.
        ++(*cursor);

        // On va vérifier si, d'après la cardinalité, on en attend d'autres
        must_continue = (_cardinality == _0_N || _cardinality == _1_N);
      }
      else {
        // On a pas validé, on arrête d'avancer
        must_continue = false;

        // Pouvait-on en avoir 0 ?
        if(!result && (_cardinality == _0_1 || _cardinality == _0_N)) {
          result = true;
        }
      }
    } while(must_continue);

    return result;
  }

}

