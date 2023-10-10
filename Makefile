CC=g++
CFLAGS=-Wall -Wextra
all: inheritance templates
inheritance:inheritance.cc inheritanceDef.hh
	$(CC) $(CFLAGS) -o $@ $@.cc

templates: templates.cc
	$(CC) $(CFLAGS) -o $@ $@.cc
clean:
	rm *.o inheritance