CC = gcc
CFLAGS =  -I$(IDIR) 

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c
all: valley run

valley:	$(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./valley

clean:
	rm valley
