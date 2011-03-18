all: parserXML

analyseXML: *.l *.y Makefile
	g++ -Wall -pedantic -ansi -g -DYYDEBUG=1 -I../ProcesseurXML/AnalyseurDTD/ -I../ProcesseurXML/AnalyseurXML/ -I../OurDom/src/ -L../ProcesseurXML/AnalyseurDTD -L../ProcesseurXML/AnalyseurXML  -lanalysedtd -lanalysexml -o analyseXML 
clean:
	rm -rf  *.output parserXML
