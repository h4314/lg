/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "common.hpp"
#include "node.hpp"
#include "element.hpp"

#include <cassert>

using namespace std;

namespace xml {

Node::Node(Element* parent) : _parent(parent)
{
//  DBG_STREAM << "Creating Node element. Parent: " << (void*)parent << endl;
}

void Node::display()
{
  assert(false); // Afficher un noeud non spécialisé est une erreur !
  DBG_STREAM << "plain node (abstract)" << endl;
}

}

