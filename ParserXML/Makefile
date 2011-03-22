CXX = g++
RELEASE= -O3
DEBUG= -DDEBUG -g
CPPFLAGS = -Wall -ansi $(LD)
LD = -Isrc/xml/ -I -Lsrc/dtd/
SRC=src
OBJ=obj
BIN=bin
DOC=doc
DEPS= $(SRC)/xml/xml.tab.c $(SRC)/xml/lex.xml.c $(OBJ)/xml/xmlparse.o $(SRC)/dtd/dtd.tab.c $(SRC)/dtd/lex.dtd.c src/dom/attribute.o  src/dom/doctype.o  src/dom/document.o  src/dom/dom.o  src/dom/element.o  src/dom/node.o  src/dom/text_node.o


$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.o
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(SRC)/xml/lex.xml.c : $(SRC)/xml/xml.l
	flex -P xml -o $(SRC)/xml/lex.xml.c $(SRC)/xml/xml.l 

$(SRC)/xml/xml.tab.c : $(SRC)/xml/xml.y $(SRC)/xml/xml.tab.h $(SRC)/xml/lex.xml.c
	bison -p xml --debug --verbose --defines=$(SRC)/xml/xml.tab.h $(SRC)/xml/xml.y -o $(SRC)/xml/xml.tab.c

$(SRC)/dtd/lex.dtd.c : $(SRC)/dtd.l
	flex -P dtd -o $(SRC)/dtd/lex.dtd.c $(SRC)/dtd/dtd.l 

$(SRC)/dtd/dtd.tab.c : $(SRC)/dtd.y $(SRC)/dtd.tab.h $(SRC)/lex.dtd.c
	bison -p dtd --debug --verbose --defines=$(SRC)/dtd/dtd.tab.h $(SRC)/dtd/dtd.y -o $(SRC)/dtd/dtd.tab.c

all : $(BIN)/parser
	@echo "done."

xml: $(SRC)/xml/xml.tab.c $(SRC)/xml/lex.xml.c $(OBJ)/xmlparse.o
	@echo "Xml done"

dtd: $(SRC)/dtd/dtd.tab.c $(SRC)/dtd/lex.dtd.c 
	@echo "DTD done"
	
clean:
	rm $(OBJ)/*
	rm $(BIN)/parser

$(BIN)/parser : $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 
