#ifndef _ADVERB_H
#define _ADVERB_H

#include<string>

using namespace std;

class Adverb
{
	public:
		Adverb(string,int);
		~Adverb();
		string getAdverbio();
		int getTipo();
	private:
		string adverbio;
		int tipo;
};

#endif
