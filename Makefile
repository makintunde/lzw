INC_DIR = include
CFLAGS = -Wall -std=c++11 -I$(INC_DIR)
TARGETS = test_suite

all: $(TARGETS)

clean:
	$(RM) $(TARGETS) *.o


test_suite: test.o lzw.o
	g++ test.o lzw.o -o test_suite 

test.o: test/test.cpp include/catch.hpp include/lzw.h
	g++  $(CFLAGS) -c test/test.cpp

lzw: lzw.o lzw_utils.o
	g++  $(CFLAGS) -o lzw.o lzw_utils.o

lzw.o: src/lzw.cpp include/lzw.h
	g++  $(CFLAGS) -c src/lzw.cpp

lzw_utils.o: src/lzw_utils.cpp include/lzw_utils.h
	g++  $(CFLAGS) -c src/lzw_utils.cpp


