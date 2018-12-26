CC = gcc
CFLAGS = -O2 -Wall -I $(CSAPP_INC) -I .
CSAPP_SRC = ../../../src
CSAPP_INC = ../../../include

all:  $(CSAPP_SRC)/csapp.o weatherAPI

$(CSAPP_SRC)/csapp.c:
	$(CSAPP_SRC)/csapp.c

$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

weatherAPI: weatherAPI.c csapp.c
	$(CC) $(CFLAGS) -o weatherAPI weatherAPI.c


clean:
	rm -f weatherAPI *~

