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
DOMDEPS=obj/dom/attribute.o  obj/dom/doctype.o  obj/dom/document.o  obj/dom/element.o  obj/dom/node.o  obj/dom/text_node.o
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
	@echo "done."

xml: $(SRC)/xml/xml.tab.c $(SRC)/xml/lex.xml.c $(OBJ)/xml/xmlparse.o
	@echo "Xml done"

dom : $(DOMDEPS) xml dtd
	@echo "DOM done"

dtd: $(SRC)/dtd/dtd.tab.c $(SRC)/dtd/lex.dtd.c 
	@echo "DTD done"


	
clean:
	rm $(OBJ)/*
	rm $(BIN)/parser

$(BIN)/parser : $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 
