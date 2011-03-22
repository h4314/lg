/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "text_node.hpp"
#include <iostream>

using namespace std;

namespace xml {

TextNode::TextNode(Element* parent, string content) 
: Node(parent), _content(content) {
  cerr << "Creating TextNode element: " << content << endl;
}

void TextNode::setContent(const std::string& content) {
  _content = content;
}

void TextNode::display()
{
cerr << "I am a text node : [" << _content << "]" << endl;
}
}

