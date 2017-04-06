CXXFLAGS=-g
CC=g++
RM=rm 

test:test.cpp
	$(CC) $(CXXFLAGS) -o $@ $<

clean:
	$(RM) -rf test
