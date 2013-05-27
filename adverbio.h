#ifndef _ADVERBIO_H
#define _ADVERBIO_H_

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include"tbb/tbb.h"
#include"tbb/task_scheduler_init.h"
#include"tbb/parallel_for.h"
#include"tbb/blocked_range.h"
#include"adverb.h"
#define MAXELEMENTOS 10000

using namespace std;
using namespace tbb;



class Adverbio
{
	public:
		Adverbio(string);
		~Adverbio();
		void openFile();
		void loadAdverbs();
		void countAdverbs();
		//void count_adverbs(const blocked_range<size_t> & r);
		void getNAdverbios();
		string getNameFile();
		int getNumLines();
		void start();
		bool delimitador(char);
		void giveValues(map<string,int>&,vector<Adverb>&,vector<int>&);
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
		struct Average;
};
#endif
