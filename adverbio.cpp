#include"adverbio.h"

Adverbio::Adverbio(string name)
{
	nameFile = name;
	file.open(nameFile.c_str());
	numLines = 0;
}

Adverbio::~Adverbio(){}

void Adverbio::openFile()
{
	if(file.is_open())
	{
		while(!file.eof())
		{
			getline(file,buffer[numLines++]);
		}
	}
}

string Adverbio::getNameFile()
{
	return nameFile;
}

int Adverbio::getNumLines()
{
	return numLines;
}

void Adverbio::printBuffer()
{
	for(int i=0;i<numLines;i++)
	{
		cout<<buffer[i]<<endl;
		int sizeTmp = buffer[i].size();
		for(int j=0;j<sizeTmp;j++)
		{
			string tmp = "";
			while(!delimitador(buffer[i][j]))
			{
				
			}
		}
		cout<<"# caracteres:\t"<<buffer[i].size()<<endl;
	}
}

bool Adverbio::delimitador(char simbol)
{
	bool flag = false;
	switch(simbol)
	{
		case ' ':case ',':case '.':case '?':
			flag = true;
		break;
	}
	return flag;
}
