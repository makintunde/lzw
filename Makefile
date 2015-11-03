INC_DIR = include
CFLAGS = -Wall -std=c++11 -I$(INC_DIR)

.PHONY: all
	all: $(TARGETS)

.PHONY: clean
	clean:
		$(RM) $(TARGETS) *.o

test: test.o
	g++ -o $(CFLAGS) testing test.o

test.o: test/test.cpp include/catch.hpp 
	g++ -c $(CFLAGS) test/test.cpp

#lzw: lzw.o lzw_utils.o
#	g++ -o $(CFLAGS) lzw.o lzw_utils.o

#lzw.o: src/lzw.cpp include/lzw.h
#	g++ -c $(CFLAGS) src/lzw.cpp

#lzw_utils.o: src/lzw_utils.cpp include/lzw_utils.h
#	g++ -c $(CFLAGS) src/lzw_utils.cpp


