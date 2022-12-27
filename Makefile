CFLAGS = -O3 -std=c++11 -Wall

all: proj

proj: p2.cpp
	g++ $(CFLAGS) p2.cpp -o p2 -lm

clean:
	rm -f *.o p2

run: proj
	./p2