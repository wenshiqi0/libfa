LIB := ./lib
SRC := ./src
INCLUDE := ./include
OUT := .
MAIN := .
CC  := gcc
LIBNAME := fa

edit: tcp.o udp.o file.o url.o map.o tree.o libfa.a out

tcp.o: $(SRC)/tcp.c $(INCLUDE)/tcp.h
	$(CC) -c $(SRC)/tcp.c -o $(LIB)/tcp.o

udp.o: $(SRC)/udp.c $(INCLUDE)/udp.h
	$(CC) -c $(SRC)/udp.c -o $(LIB)/udp.o

file.o: $(SRC)/file.c $(INCLUDE)/file.h
	$(CC) -c $(SRC)/file.c -o $(LIB)/file.o

url.o: $(SRC)/url.c $(INCLUDE)/url.h
	$(CC) -c $(SRC)/url.c -o $(LIB)/url.o

map.o: $(SRC)/map.c $(INCLUDE)/map.h
	$(CC) -c $(SRC)/map.c -o $(LIB)/map.o

tree.o: $(SRC)/tree.c $(INCLUDE)/tree.h
	$(CC) -c $(SRC)/tree.c -o $(LIB)/tree.o

libfa.a: $(LIB)/tcp.o $(LIB)/udp.o $(LIB)/file.o $(LIB)/url.o $(LIB)/map.o $(LIB)/tree.o
	ar rc $(LIB)/libfa.a $(LIB)/tcp.o $(LIB)/udp.o $(LIB)/file.o $(LIB)/url.o $(LIB)/map.o $(LIB)/tree.o

out: $(LIB)/libfa.a
	$(CC) $(in) -o $(out) -L $(LIB) -l$(LIBNAME)
