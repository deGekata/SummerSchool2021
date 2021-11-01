# Это комментарий, который говорит, что переменная CC указывает компилятор, используемый для сборки
CC=g++
#Это еще один комментарий. Он поясняет, что в переменной CFLAGS лежат флаги, которые передаются компилятору
CFLAGS= -g -std=c++14 -Wall -Wextra -Weffc++ -Wc++0x-compat -Wc++11-compat -Wc++14-compat -Waggressive-loop-optimizations  -Warray-bounds -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2  -Winline -Wlarger-than=8192  -Wlogical-op -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-promo -Wstack-usage=8192 -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wnarrowing -Wno-old-style-cast -Wvarargs -fcheck-new -fsized-deallocation -fstack-check -fstrict-overflow -fchkp-first-field-has-own-bounds -fchkp-narrow-to-innermost-array -flto-odr-type-merging
BuildF="Build/"

all: ASSembler DisASSembler Invoker






StringFileParser.o: 
	$(CC) -c $(CFLAGS) Libs/StringLib/StringFileParser.cpp -o  $(BuildF)StringFileParser.o

Shared.o:
	$(CC) -c $(CFLAGS) Shared/Shared.cpp -o $(BuildF)Shared.o	




ASSembler: ASSembler.o Lexer.o ASSemblerMain.o Shared.o StringFileParser.o
	$(CC) $(BuildF)ASSembler.o $(BuildF)Lexer.o $(BuildF)ASSemblerMain.o $(BuildF)Shared.o $(BuildF)StringFileParser.o -o ass.out

ASSembler.o:
	$(CC) -c $(CFLAGS) ASSembler/ASSembler.cpp -o  $(BuildF)ASSembler.o

Lexer.o:
	$(CC) -c $(CFLAGS) ASSembler/Lexer.cpp -o  $(BuildF)Lexer.o

ASSemblerMain.o:
	$(CC) -c $(CFLAGS) ASSembler/main.cpp -o  $(BuildF)ASSemblerMain.o



DisASSembler: DisASSemblerMain.o DisASSembler.o Shared.o StringFileParser.o
	$(CC) $(CFLAGS) $(BuildF)DisASSembler.o $(BuildF)DisASSemblerMain.o $(BuildF)Shared.o $(BuildF)StringFileParser.o -o double_ass.out

DisASSembler.o:
	$(CC) -c $(CFLAGS) DisASSembler/DisASSembler.cpp -o $(BuildF)DisASSembler.o

DisASSemblerMain.o:
	$(CC) -c $(CFLAGS) DisASSembler/main.cpp -o $(BuildF)DisASSemblerMain.o



Invoker: Invoker.o InvokerMain.o Stack.o Shared.o StringFileParser.o
	$(CC) $(BuildF)Invoker.o $(BuildF)InvokerMain.o $(BuildF)Stack.o $(BuildF)Shared.o $(BuildF)StringFileParser.o -o invoker.out -lSDL2 -lSDL2main

InvokerMain.o: 
	$(CC) -c $(CFLAGS) Invoker/main.cpp -o $(BuildF)InvokerMain.o 

Invoker.o:
	$(CC) -c $(CFLAGS) Invoker/Invoker.cpp -o $(BuildF)Invoker.o -lSDL2 -lSDL2main

Stack.o:
	$(CC) -c $(CFLAGS) Libs/Stack/MyStack.cpp -o $(BuildF)Stack.o


clean:
	rm -rf *.o hello

#ASSembler:
#	$(CC)  -lSDL2 -lSDL2main -o ASSembler

#g++ ASSembler/ASSembler.cpp ASSembler/Lexer.cpp ASSembler/main.cpp Shared/Shared.cpp Libs/StringLib/StringFileParser.cpp -o ASSembler.out