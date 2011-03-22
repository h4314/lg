CXX = g++
RELEASE= -O3
DEBUG= -DDEBUG -g
CPPFLAGS = -Wall -ansi -shared $(LD)
LD = -I../AnalyseurDTD/src -L../AnalyseurDTD/ -lanalysedtd 
SRC=src
OBJ=obj
BIN=bin
DOC=doc
DEPS=$(SRC)/xml.tab.c $(SRC)/lex.xml.c $(OBJ)/xmlparse.o  


$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(SRC)/lex.xml.c : $(SRC)/xml.l
	flex -P xml -o $(SRC)/lex.xml.c $(SRC)/xml.l 

$(SRC)/xml.tab.c : $(SRC)/xml.y $(SRC)/xml.tab.h $(SRC)/lex.xml.c
	bison -p xml --debug --verbose --defines=$(SRC)/xml.tab.h $(SRC)/xml.y -o $(SRC)/xml.tab.c

all : $(BIN)/libanalysexml.so
	@echo "done."

clean:
	rm $(SRC)/xml.tab.c
	rm $(SRC)/lex.xml.c
	rm $(OBJ)/*
	rm $(BIN)/libanalysexml.so

$(BIN)/libanalysexml.so : $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 
