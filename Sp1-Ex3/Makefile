# define variables:
CC = gcc
FLAGS = -Wall -g

.PHONY: all clean

all: StrList
clean:
	rm -f *.o StrList

# create runfile:
StrList: StrList.o Main.o
	$(CC) $(FLAGS) StrList.o Main.o -o StrList

# create o files:
StrList.o: StrList.c StrList.h
	$(CC) $(FLAGS) -c StrList.c -o StrList.o

Main.o: Main.c StrList.h
	$(CC) $(FLAGS) -c Main.c -o Main.o