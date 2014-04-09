CC = gcc
CFLAGS = -Wall -g
LIB = -Iinclude

all: main


main: lexxYacc codemonC javaMake
	$(CC) $(CFLAGS) $(LIB) -Wno-unused-function -I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers -o libcodemonCompiler.jnilib -fPIC -shared lex.yy.c y.tab.c -ll obj/codemonCompiler.o obj/client.o obj/labelList.o obj/CodeParser.o
	export CLASSPATH="${CLASSPATH}:./mysql.jar"
	export LD_LIBRARY_PATH="${LD_LIBRARY_PATH}:."

testMain: client list codeParser
	$(CC) $(CFLAGS) $(LIB) -c src/testMain.c -o obj/testMain.o
	$(CC) -o ./codemonRun obj/testMain.o obj/CodeParser.o obj/client.o obj/labelList.o
	
testYacc:
	yacc -d -y src/yaccer.yacc
	lex -i src/lexxer.lex
	gcc -c y.tab.c
	gcc -c lex.yy.c
	gcc -o ./codemonRun lex.yy.o y.tab.o -ll

codemonC: client list codeParser
	$(CC) $(CFLAGS) $(LIB) -I. -I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers -c src/codemonCompiler.c -o obj/codemonCompiler.o

client:
	$(CC) $(CFLAGS) $(LIB) -c src/client.c -o obj/client.o -D_TRACE

list:
	$(CC) $(CFLAGS) $(LIB) -c src/labelList.c  -o obj/labelList.o

codeParser:
	$(CC) $(CFLAGS) $(LIB) -c src/CodeParser.c -o obj/CodeParser.o

lexxYacc:
	yacc -d -y src/yaccer.yacc
	lex -i src/lexxer.lex

javaMake:
	javac src/codemonGui.java -d .

run:
	java -cp .:mysql.jar codemonPkg4/JFurlone/A4/codemonGui
	
clean:
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	rm obj/*.o
	rm codemonPkg4/JFurlone/A4/*.class
	rm libcodemonCompiler.jnilib
	rm -r libcodemonCompiler.jnilib.dSYM
	rm Codemon/*.codemon

cleantest:
	rm obj/*.o
	rm ./codemonRun
	rm -r codemonRun.dSYM