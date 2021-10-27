# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=gcc
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS=-c -Wall
BuildF="Build/"

all: ASSembler DisASSembler Invoker






StringFileParser.o: 
	$(CC) $(CFLAGS) Libs/StringLib/StringFileParser.cpp -o  $(BuildF)StringFileParser.o

Shared.o:
	$(CC) $(CFLAGS) Shared/Shared.cpp -o $(BuildF)Shared.o	




ASSembler: ASSembler.o Lexer.o ASSemblerMain.o Shared.o StringFileParser.o
	$(CC) $(BuildF)ASSembler.o $(BuildF)Lexer.o $(BuildF)ASSemblerMain.o $(BuildF)Shared.o $(BuildF)StringFileParser.o -o ass.out

ASSembler.o:
	$(CC) $(CFLAGS) ASSembler/ASSembler.cpp -o  $(BuildF)ASSembler.o

Lexer.o:
	$(CC) $(CFLAGS) ASSembler/Lexer.cpp -o  $(BuildF)Lexer.o

ASSemblerMain.o:
	$(CC) $(CFLAGS) ASSembler/main.cpp -o  $(BuildF)ASSemblerMain.o



DisASSembler: DisASSemblerMain.o DisASSembler.o Shared.o StringFileParser.o
	$(CC) $(BuildF)DisASSembler.o $(BuildF)DisASSemblerMain.o $(BuildF)Shared.o $(BuildF)StringFileParser.o -o double_ass.out

DisASSembler.o:
	$(CC) $(CFLAGS) DisASSembler/DisASSembler.cpp -o $(BuildF)DisASSembler.o

DisASSemblerMain.o:
	$(CC) $(CFLAGS) DisASSembler/main.cpp -o $(BuildF)DisASSemblerMain.o



Invoker: Invoker.o InvokerMain.o Stack.o Shared.o StringFileParser.o
	$(CC) $(BuildF)Invoker.o $(BuildF)InvokerMain.o $(BuildF)Stack.o $(BuildF)Shared.o $(BuildF)StringFileParser.o -o invoker.out -lSDL2 -lSDL2main

InvokerMain.o: 
	$(CC) $(CFLAGS) Invoker/main.cpp -o $(BuildF)InvokerMain.o 

Invoker.o:
	$(CC) $(CFLAGS) Invoker/Invoker.cpp -o $(BuildF)Invoker.o -lSDL2 -lSDL2main

Stack.o:
	$(CC) $(CFLAGS) Libs/Stack/MyStack.cpp -o $(BuildF)Stack.o


clean:
	rm -rf *.o hello

#ASSembler:
#	$(CC)  -lSDL2 -lSDL2main -o ASSembler

#g++ ASSembler/ASSembler.cpp ASSembler/Lexer.cpp ASSembler/main.cpp Shared/Shared.cpp Libs/StringLib/StringFileParser.cpp -o ASSembler.out