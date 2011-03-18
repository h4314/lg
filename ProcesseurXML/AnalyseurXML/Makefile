all: analyseXML

analyseXML: *.l *.y Makefile
	flex  -P xml xml.l
	bison --debug --verbose -p xml --defines=xml.tab.h xml.y
	g++ -Wall -pedantic -ansi -g -DYYDEBUG=1 -I../AnalyseurDTD/ -L../AnalyseurDTD -lanalysedtd -o analyseXML  lex.xml.c  xml.tab.c xmlparse.cpp ../AnalyseurDTD/dtd.tab.c ../AnalyseurDTD/lex.dtd.c 
clean:
	rm -rf *.tab.c lex.*.c *.tab.h *.output analyseXML

