/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "document.hpp"

using namespace std;

namespace xml {

Document::Document(std::istream instream):
  _instream(instream), _xmlElement(), _doctype(0) {
}

Document::setRoot(Element& element) {
  _xmlElement = element;
}

Document::setDoctype(Doctype& doctype) {
  _doctype = &doctype;
}

}

