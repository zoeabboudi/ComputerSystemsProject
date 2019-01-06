CC = gcc

CSAPP_INC = ../../../include
CSAPP_SRC = ../../../src

CFLAGS = -Wall -O2 -I $(CSAPP_INC) -I .
LDLIBS = -lpthread

all: $(CSAPP_SRC)/csapp.o  SemesterProject
$(PROGS): $(CSAPP_SRC)/csapp.o
$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

tiny/tiny: tiny/tiny.c
        (cd tiny; make)CC = gcc
SemesterProject: SemesterProject.c $(CSAPP_SRC)/csapp.o
        $(CC) $(CFLAGS) -o SemesterProject SemesterProject.c $(CSAPP_SRC)/csapp.o -lpthread

clean:
        rm -f SemesterProject *~
                                                                                                                  
