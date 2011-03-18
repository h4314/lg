/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "doctype.hpp"

using namespace std;

namespace xml {

Doctype::Doctype(): Doctype(string("")) {
}

Doctype::Doctype(string name): _name(name) {
}

}

