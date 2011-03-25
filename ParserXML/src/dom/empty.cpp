/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "empty.hpp"
#include <iostream>

using namespace std;

namespace xml {

Empty::Empty()
{
  cerr << "Creating doctype element: " << name << endl;
}

bool Empty::valid()
{
  return false;
}

}

