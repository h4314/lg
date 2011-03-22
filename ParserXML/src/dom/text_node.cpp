/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "text_node.hpp"

using namespace std;

namespace xml {

TextNode::TextNode(Element* parent, string content) : Node(parent), _content(content) {
}

void TextNode::setContent(string content) {
  _content = content;
}

}

