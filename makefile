all:
	g++ -c adverb.cpp
	g++ -c adverbio.cpp
	g++ main.cpp -o main adverbio.o adverb.o -ltbb
clean:
	rm adverbio.o
	rm adverb.o
