#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <string>

#include "dom.hpp"

void handle_dtd(const std::string& filename);
void parseXML(xml::Document * doc);

extern int xmlparse();


static xml::Document * document = 0;
static xml::Element * current = 0;

#endif // XMLPARSE_H
