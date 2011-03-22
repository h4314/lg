/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "doctype.hpp"
#include <iostream>

using namespace std;

namespace xml {

Doctype::Doctype(const std::string& name)
:_name(name) 
{
  cerr << "Creating doctype element: " << name << endl;
}

}

