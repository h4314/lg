CXX = g++
RELEASE= -O3
DEBUG= -DDEBUG -g
CPPFLAGS = -Wall -ansi -shared $(LD)
LD=
SRC=src
OBJ=obj
BIN=.
DOC=doc
DEPS=$(SRC)/dtd.tab.c $(SRC)/lex.dtd.c 


$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(SRC)/lex.dtd.c : $(SRC)/dtd.l
	flex -P dtd -o $(SRC)/lex.dtd.c $(SRC)/dtd.l 

$(SRC)/dtd.tab.c : $(SRC)/dtd.y $(SRC)/dtd.tab.h $(SRC)/lex.dtd.c
	bison -p dtd --debug --verbose --defines=$(SRC)/dtd.tab.h $(SRC)/dtd.y -o $(SRC)/dtd.tab.c

all : $(BIN)/libanalysedtd.so
	@echo "done."

clean:
	rm $(SRC)/dtd.tab.c
	rm $(SRC)/lex.dtd.c
	rm $(BIN)/libanalysedtd.so

$(BIN)/libanalysedtd.so : $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 
