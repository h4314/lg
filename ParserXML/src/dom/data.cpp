/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "data.hpp"
#include <iostream>

using namespace std;

namespace xml {

Data::Data()
{
  cerr << "Creating doctype element: " << name << endl;
}

bool Data::valid(Element* elt)
{
  Node* child; // TODO fils de elt
  // Est un noeud texte ?
  return dynamic_cast<TextNode*>(child);
}

}

