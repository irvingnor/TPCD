#ifndef _ADVERBIO_H
#define _ADVERBIO_H_

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include"tbb/parallel_for.h"
#include"adverb.h"
#define MAXELEMENTOS 10000

using namespace std;

class Adverbio
{
	public:
		Adverbio(string);
		~Adverbio();
		void openFile();
		void loadAdverbs();
		void countAdverbs();
		string getNameFile();
		int getNumLines();
		void start();
		bool delimitador(char);
	private:
		ifstream file;
		ifstream listAdverbios;
		string nameFile;
		int numLines;
		int numWords;
		string buffer[MAXELEMENTOS];
		map<string,int> dFile;
		vector<Adverb> list;
		vector<int> nAdverbios;
};


#endif
