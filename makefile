BINDIR = ./tmpbin
all: build

stack.o : stack.c 
	gcc -c -o $(BINDIR)/stack.o stack.c

jane.o : jane.c stack.o
	gcc -c -o $(BINDIR)/jane.o jane.c

j	: jane.o stack.o
	gcc -o j $(BINDIR)/jane.o $(BINDIR)/stack.o

build: stack.o jane.o j
