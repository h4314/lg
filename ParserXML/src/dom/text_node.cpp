/**
 * == Analyseur XML simplifié ==
 * @authors Hexanome 4314
 */

#include "common.hpp"
#include "text_node.hpp"

using namespace std;

namespace xml {

TextNode::TextNode(Element* parent, string content)
  : Node(parent), _content(content) {
  // DBG_STREAM << "Creating TextNode element: " << content << endl;
}

void TextNode::setContent(const string& content) {
  _content = content;
}

void TextNode::display() {
  DBG_STREAM << "<![CDATA[" << _content << "]>" << endl;
}

}

