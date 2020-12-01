CC = gcc
FLAGS = -Wall 
HEADER = myBank.h
OBJECTS_MAIN = main.o

all:  main.o myBank.a
	$(CC) $(FLAGS) -o all $(OBJECTS_MAIN) myBank.a

myBank.a: myBank.o 
	ar rcs myBank.a myBank.o 

main.o: main.c $(HEADER)
	$(CC) $(FLAGS) -c main.c

myBank.o: myBank.c $(HEADER)
	$(CC) $(FLAGS) -c myBank.c	

.PHONY: clean all 

clean:
	rm -f *.o *.a all