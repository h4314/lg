/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "doctype.hpp"
#include <iostream>

using namespace std;

namespace xml {

Doctype::Doctype(string name): _name(name) {
	std::cerr << __LINE__ << ":" << __FILE__ << std::endl;
}

}

