CC=gcc -std=c99
CFLAGS=-g -Wall -Wextra -O0
LDFLAGS=
SOURCES=check_htp.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=work1

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@