all:
	g++ -c adverbio.cpp
	g++ main.cpp -o main adverbio.o
clean:
	rm adverbio.o
