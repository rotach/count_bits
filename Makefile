SRC=src
INC=include
LIB=.
BUILD=build
BIN=bin

CC=gcc
CCFLAGS=-I$(INC) -Wall -O
LDFLAGS=-L$(LIB) #-lxyz
AR=ar

c: $(BIN)/count_bits $(BIN)/popcount $(BIN)/gcc_popcount

$(BIN)/count_bits: count_bits.o
	$(CC) $(BUILD)/count_bits.o -o $(BIN)/count_bits $(LDFLAGS)

count_bits.o: $(SRC)/count_bits.c $(INC)/count_bits.h
	$(CC) $(CCFLAGS) -c $(SRC)/count_bits.c -o $(BUILD)/count_bits.o

$(BIN)/popcount: popcount.o
	$(CC) $(BUILD)/popcount.o -o $(BIN)/popcount $(LDFLAGS)

popcount.o: $(SRC)/popcount.c $(INC)/count_bits.h
	$(CC) $(CCFLAGS) -c $(SRC)/popcount.c -o $(BUILD)/popcount.o

$(BIN)/gcc_popcount: gcc_popcount.o
	$(CC) $(BUILD)/gcc_popcount.o -o $(BIN)/gcc_popcount $(LDFLAGS)

gcc_popcount.o: $(SRC)/gcc_popcount.c $(INC)/count_bits.h
	$(CC) $(CCFLAGS) -c $(SRC)/gcc_popcount.c -o $(BUILD)/gcc_popcount.o

all: c

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/*
