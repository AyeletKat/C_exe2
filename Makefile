# Flags and commands
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean
#make all = make both our exe files
all: my_graph my_Knapsack
################################_neighbors matrix compiling
my_graph: my_graph.o libmymath.a
	gcc $(CFLAGS) $^ -o $@

libmymath.a: my_mat.o
	ar $(AFLAGS) $@ $<

my_graph.o: my_graph.c my_mat.h
	gcc $(CFLAGS) -c $<

my_mat.o: my_mat.c my_mat.h
	gcc $(CFLAGS) -c $<
##################################_DP problem compiling
my_Knapsack: my_Knapsack.o
	gcc $(CFLAGS) my_Knapsack.o -o my_Knapsack

my_Knapsack.o: my_Knapsack.c
	gcc $(CFLAGS) -c my_Knapsack.c

clean:
	rm -f *.o *.a my_graph my_Knapsack
