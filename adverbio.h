#ifndef _ADVERBIO_H
#define _ADVERBIO_H_

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#define MAXELEMENTOS 500

using namespace std;

class Adverbio
{
	public:
		Adverbio(string);
		~Adverbio();
		void openFile();
		string getNameFile();
		int getNumLines();
		void printBuffer();
		bool delimitador(char);
	private:
		ifstream file;
		string nameFile;
		int numLines;
		int numWords;
		string buffer[MAXELEMENTOS];
		map<string,int> dFile;
};

#endif
