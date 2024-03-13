CFLAGS = -Wall 
CC = gcc
SOURCES = $(wildcard *.c)
TARGETS = $(patsubst %.c, %.out, $(SOURCES))
LIBS = -lm

all: $(TARGETS)

%.out: %.c
	    $(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	    rm *.out
