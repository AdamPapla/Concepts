CC=g++
CFLAGS=-Wall -Wextra
all: inheritance templates
inheritance:inheritance.cc inheritanceDef.hh
	$(CC) $(CFLAGS) -o $@ $@.cc

templates: templates.cc templates.hh
	$(CC) $(CFLAGS) -o $@ $@.cc
clean:
	rm *.o inheritance