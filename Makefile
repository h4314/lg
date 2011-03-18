CXX = g++
RELEASE= -O3
DEBUG= -DDEBUG -g
CPPFLAGS = -Wall -ansi $(LD)
LD = -lanalysexml -lanalysedtd
SRC=src
OBJ=obj
BIN=bin
DOC=doc
DEPS=


$(OBJ)/%.o : $(SRC)/%.cpp $(SRC)/%.hpp
	$(CXX) $(CPPFLAGS) -c $< -o $@
$(OBJ)/%.o : $(SRC)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all : $(BIN)/parserXML

$(BIN)/parserXML : $(DEPS)
	$(CXX) $(CPPFLAGS) $+ -o $@ 

clean :
	rm $(OBJ)/*.o $(BIN)/*

$(OBJ)/main.o : $(SRC)/fileshareServer.hpp $(SRC)/settingsManager.hpp
$(OBJ)/fileshareServer.o : $(SRC)/inotify-cxx.hpp $(SRC)/eventManager.hpp $(SRC)/settingsManager.hpp
$(OBJ)/eventManager.o : $(SRC)/distantLockManager.hpp $(SRC)/inotify-cxx.hpp $(SRC)/settingsManager.hpp
$(OBJ)/distantLockManager.o : $(SRC)/inotify-cxx.hpp $(SRC)/networkManager.hpp $(SRC)/settingsManager.hpp $(SRC)/fileInfo.hpp
$(OBJ)/networkManager.o : $(SRC)/inotify-cxx.hpp $(SRC)/settingsManager.hpp $(SRC)/localLocker.hpp $(SRC)/rsyncWrapper.hpp  $(SRC)/server.hpp
$(OBJ)/rsyncWrapper.o : $(SRC)/fileshareServer.hpp $(SRC)/log.hpp $(SRC)/server.hpp $(SRC)/fileInfo.hpp
$(OBJ)/event.o : $(SRC)/log.hpp $(SRC)/fsObject.hpp
$(OBJ)/fileInfo.o : $(SRC)/fsObject.hpp $(SRC)/localLocker.hpp $(SRC)/log.hpp
