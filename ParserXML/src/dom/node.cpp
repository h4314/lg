/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "node.hpp"
#include "element.hpp"

#include <iostream>

using namespace std;

namespace xml {

Node::Node(Element* parent) 
	:parent_(parent)
{
  cerr << "Creating Node element. Parent: " << (void*)parent << endl;
}

Element* Node::parent() {
	return parent_;
}

void Node::display()
{
  std::cerr << "I am a plain node" << std::endl;
}

}

