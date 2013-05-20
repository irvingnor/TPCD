#include"adverb.h"

Adverb::Adverb(string adverbio1,int tipo1)
{
	adverbio = adverbio1;
	tipo = tipo1;
}

Adverb::~Adverb(){}

string Adverb::getAdverbio()
{
	return adverbio;
}

int Adverb::getTipo()
{
	return tipo;
}
