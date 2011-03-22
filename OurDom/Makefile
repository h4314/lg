CXX = g++
RELEASE= -O3
DEBUG= -DDEBUG -g
CPPFLAGS = -Wall -ansi $(LD)
LD =
SRC=src
OBJ=obj
BIN=bin
DOC=doc
DEPS=$(SRC)/attribute.o  $(SRC)/doctype.o  $(SRC)/document.o  $(SRC)/element.o  $(SRC)/node.o  $(SRC)/text_node.o $(SRC)/main.o
TARGET=test_dom



$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all : $(BIN)/$(TARGET)
	@echo "done."

clean:
	rm $(OBJ)/*
	rm $(BIN)/$(TARGET)

$(BIN)/$(TARGET): $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 
