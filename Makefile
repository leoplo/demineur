CC = gcc
CFLAGS = -g -Wall
SRCS = main.c menu.c mines.c  grille.c
OBJS = $(SRCS:.c=.o)
MAIN = main

.PHONY: depend clean

all: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ *# $(MAIN)

depend: $(SRCS)
	makedepend $^
