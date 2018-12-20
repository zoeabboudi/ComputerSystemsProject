CC = gcc

CSAPP_INC = ../../../include
CSAPP_SRC = ../../../src

CFLAGS = -Wall -O2 -I $(CSAPP_INC) -I .
LDLIBS = -lpthread

all: $(CSAPP_SRC)/csapp.o semesterProject
$(PROGS): $(CSAPP_SRC)/csapp.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

tiny/tiny: tiny/tiny.c
	(cd tiny; make)CC = gcc

adder: adder.c
	$(CC) $(CFLAGS) -o adder adder.c
semesterProject: semesterProject.c $(CSAPP_SRC)/csapp.o
	$(CC) $(CFLAGS) -o semesterProject semesterProject.c $(CSAPP_SRC)/csapp.o -lpthread

subtract: subtract.c
	$(CC) $(CFLAGS) -o subtract subtract.c
clean:
	rm -f adder *~
	rm -f subtract *~
	rm -f semesterProject *~
