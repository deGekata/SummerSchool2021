CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=MyStack.cpp MyStack.h StackConfig.h source.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Stack

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@