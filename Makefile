EXEC = shell
SRC = main.c //shell.c fs.c aux.c process_stuff.c
CC = gcc
CFLAGS = -g -Wall

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

run: $(EXEC)
	./$(EXEC)

clean:
	rm -f $(EXEC) *.o


