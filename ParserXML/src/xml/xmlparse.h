#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <string>
#include <cstdio>

#include "dom.hpp"

void handle_dtd(const std::string& filename);
bool parseXML(FILE* f, xml::Document * doc);

int xmlparse();


extern xml::Document* document_;
extern xml::Element* current_;


#endif // XMLPARSE_H
