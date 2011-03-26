/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "document.hpp"
#include "xmlparse.h"
#include <cassert>

using namespace std;

namespace xml {

  Document::Document(FILE* f):
    f_(f), _xmlElement(0), _doctype(0) {
    }

  void Document::setRoot(Element* element) {
    _xmlElement = element;
  }

  void Document::setDoctype(Doctype* doctype) {
    assert(this != 0);
    _doctype = doctype;
  }

  bool Document::parse() {
    return parseXML(f_, this);
  }

}

