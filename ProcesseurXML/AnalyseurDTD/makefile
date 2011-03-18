all: analyseDTD
analyseDTD: *.l *.y makefile
	flex -P dtd dtd.l
	#bison -p dtd --debug --verbose --defines=dtd.tab.h dtd.y g++ -shared -g -DdtdDEBUG=1 -o libanalysedtd.so  lex.dtd.c dtd.tab.c 
	bison -p dtd --debug --verbose --defines=dtd.tab.h dtd.y
	g++ -shared -g  -o libanalysedtd.so  lex.dtd.c dtd.tab.c 
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output analyseDTD

