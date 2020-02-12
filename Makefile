CC=gcc
CFLAGS=-c -Wall -O3
LDFLAGS=
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=pageRank

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)

re: clean all
