/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "node.hpp"
#include "element.hpp"

using namespace std;

namespace xml {

Node::Node(Element* parent) 
	:parent_(parent)
{
}

Element* Node::parent() {
	return parent_;
}

}

