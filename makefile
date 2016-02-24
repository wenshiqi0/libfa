LIB := ./lib
SRC := ./src
INCLUDE := ./include
OUT := .
MAIN := .
CC  := gcc
LIBNAME := fa

edit: tcp.o udp.o file.o libfa.a out

tcp.o: $(SRC)/tcp.c $(INCLUDE)/tcp.h
	$(CC) -c $(SRC)/tcp.c -o $(LIB)/tcp.o

udp.o: $(SRC)/udp.c $(INCLUDE)/udp.h
	$(CC) -c $(SRC)/udp.c -o $(LIB)/udp.o

file.o: $(SRC)/file.c $(INCLUDE)/file.h
	$(CC) -c $(SRC)/file.c -o $(LIB)/file.o

libfa.a: $(LIB)/tcp.o $(LIB)/udp.o $(LIB)/file.o $(LIB)/video.o
	ar rc $(LIB)/libfa.a $(LIB)/tcp.o $(LIB)/udp.o $(LIB)/file.o $(LIB)/video.o

out: $(LIB)/libfa.a $(INCLUDE)/tcp.h $(INCLUDE)/udp.h $(INCLUDE)/file.h
	$(CC) $(in) -o $(out) -L $(LIB) -l$(LIBNAME)
