CC=gcc
OPT=-Wall -g -std=c99
SRC = $(wildcard src/*.c)
OBJS = $(SRC:.c=.o)
EXEC=hangman
all : $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OPT) -o $@ $^
%.o : %.c
	$(CC) $(OPT) -o $@ -c $<
clean:
	rm -rf src/*.o hangman src/*.stackdump
