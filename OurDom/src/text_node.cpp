/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "text_node.hpp"

using namespace std;

namespace xml {

TextNode::TextNode(string content) : Node(), _content(content) {
}

void TextNode::setContent(string content) {
  _content = content;
}

}

