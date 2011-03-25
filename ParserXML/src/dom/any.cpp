/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "any.hpp"
#include <iostream>

using namespace std;

namespace xml {

Any::Any()
{
  cerr << "Creating doctype element: " << name << endl;
}

bool Any::valid()
{
  return true;
}

}

