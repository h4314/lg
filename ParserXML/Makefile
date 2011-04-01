CXX = g++
RELEASE= -O3
DEBUG=
CPPFLAGS = -Wall -ansi $(LD) -g -DDEBUG 
LD = -Isrc/xml/ -Isrc/dtd/ -Isrc/dom/
SRC=src
OBJ=obj
BIN=bin
DOC=doc
DEPS=$(SRC)/dtd/dtd.tab.c $(SRC)/dtd/lex.dtd.c 
XMLDEPS=$(SRC)/xml/xml.tab.c $(SRC)/xml/lex.xml.c $(SRC)/xml/xmlparse.o
DOMDEPS= obj/dom/alt_validator.o obj/dom/any_validator.o obj/dom/attribute.o obj/dom/data_validator.o obj/dom/doctype.o obj/dom/document.o obj/dom/dtd_element.o obj/dom/dtd_validator.o obj/dom/element.o obj/dom/empty_validator.o obj/dom/multiple_validator.o obj/dom/node.o obj/dom/seq_validator.o obj/dom/text_node.o obj/dom/xml_element_validator.o

DEPS+=$(DOMDEPS) $(XMLDEPS) $(OBJ)/main.o 

$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.o
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o : $(SRC)/%.c
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(SRC)/xml/lex.xml.c : $(SRC)/xml/xml.l
	flex -P xml -o $(SRC)/xml/lex.xml.c $(SRC)/xml/xml.l 

$(SRC)/xml/xml.tab.c : $(SRC)/xml/xml.y $(SRC)/xml/xml.tab.h $(SRC)/xml/lex.xml.c
	bison -p xml --debug --verbose --defines=$(SRC)/xml/xml.tab.h $(SRC)/xml/xml.y -o $(SRC)/xml/xml.tab.c

$(SRC)/dtd/lex.dtd.c : $(SRC)/dtd/dtd.l
	flex -P dtd -o $(SRC)/dtd/lex.dtd.c $(SRC)/dtd/dtd.l 

$(SRC)/dtd/dtd.tab.c : $(SRC)/dtd/dtd.y $(SRC)/dtd/dtd.tab.h $(SRC)/dtd/lex.dtd.c
	bison -p dtd --debug --verbose --defines=$(SRC)/dtd/dtd.tab.h $(SRC)/dtd/dtd.y -o $(SRC)/dtd/dtd.tab.c

all : $(BIN)/parser
	@echo "Compilation OK"
	(cd ../Tests/ && ./unit_test.sh)

xml: $(SRC)/xml/xml.tab.c $(SRC)/xml/lex.xml.c $(OBJ)/xml/xmlparse.o
	@echo "Xml done"

dom : $(DOMDEPS) xml dtd
	@echo "DOM done"

dtd: $(SRC)/dtd/dtd.tab.c $(SRC)/dtd/lex.dtd.c 
	@echo "DTD done"


clean:
	find . -name "*.o" -exec rm {} \;
	rm src/xml/xml.tab.c
	rm src/dtd/dtd.tab.c
	rm bin/parser

$(BIN)/parser : $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 
