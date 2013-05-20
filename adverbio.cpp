#include"adverbio.h"

Adverbio::Adverbio(string name)
{
	nameFile = name;
	file.open(nameFile.c_str());
	numLines = numWords = 0;
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
	vector<string> palabras;
	for(int i=0;i<numLines;i++)
	{
		cout<<buffer[i]<<endl;
		int sizeTmp = buffer[i].size();
		for(int j=0;j<sizeTmp;j++)
		{
			string tmp = "";
			while(!delimitador(buffer[i][j]))
			{
				tmp+=buffer[i][j++];
			}
			palabras.push_back(tmp);
			numWords++;
			if(dFile[tmp] == 0)
			{
				dFile[tmp] = 1;
			}
			else
			{
				dFile[tmp]++;
			}
		}
		//cout<<"# caracteres:\t"<<buffer[i].size()<<endl;
	}
	
	
	cout<<"-------------------------"<<endl;
	int tam = palabras.size();
	for(int i=0;i<tam;i++)
	{
		cout<<palabras[i]<<"\t";
	}
	cout<<"--------------------------"<<endl;
	
	cout<<"Numero de palabras:\t"<<numWords<<endl;
	string tmp = "";
	cin>>tmp;
	cout<<"Esta:\t"<<dFile[tmp]<<endl;
	//cout<<endl<<endl<<endl;
}

bool Adverbio::delimitador(char simbol)
{
	bool flag = false;
	switch(simbol)
	{
		case ' ':case ',':case '.':case '?':case ':':case '/':
		case '#':case '-':case '(':case ')':case '\n':case '{':
		case '}':case '%':
			flag = true;
		break;
	}
	return flag;
}
