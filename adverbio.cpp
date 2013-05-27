#include"adverbio.h"

Adverbio::Adverbio(string name)
{
	nameFile = name;
	numLines = numWords = 0;
}

Adverbio::~Adverbio(){}

void Adverbio::openFile()
{
	file.open(nameFile.c_str());
	if(file.is_open())
	{
		while(!file.eof())
		{
			getline(file,buffer[numLines++]);
		}
	}
	file.close();
}

void Adverbio::loadAdverbs()
{
	string nameTmp = "adverbis.lst";
	
	listAdverbios.open(nameTmp.c_str());
	
	if(listAdverbios.is_open())
	{
		while(!listAdverbios.eof())
		{
			string tmp = "";
			getline(listAdverbios,tmp);
			cout<<tmp<<endl;
			int tipo = tmp[1] - '0';
			int size = tmp.size();
			for(int i=4;i<size-1;i++)
			{
				string word = "";
				while(tmp[i] !=',' && i<size-1)
				{
					word += tmp[i++];
				}
				cout<<word<<"\ttipo:\t"<<tipo<<endl;
				Adverb advTmp(word,tipo);
				list.push_back(advTmp);
			}
		}
	}
	listAdverbios.close();
}

void Adverbio::countAdverbs()
{
	int size = list.size();
	int tipo = 1;
	for(int i=0;i<size;i++)
	{

		while(list[i].getTipo() == tipo)
		{
					
			nAdverbios[nAdverbios.size()-1]+= dFile[list[i].getAdverbio()];
			cout<<list[i].getAdverbio()<<endl;
			i++;
		}
		tipo = list[i].getTipo();
		i--;
	}
	
	size = nAdverbios.size();
	for(int i=0;i<size;i++)
	{
		cout<<"Existen\t"<<nAdverbios[i]<<"\tde tipo "<<i+1<<endl;
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

void Adverbio::start()
{
	vector<string> palabras;
	for(int i=0;i<numLines;i++)
	{
		//cout<<buffer[i]<<endl;
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
	
	/*
	cout<<"-------------------------"<<endl;
	int tam = palabras.size();
	for(int i=0;i<tam;i++)
	{
		cout<<palabras[i]<<"\t";
	}
	cout<<"--------------------------"<<endl;
	*/
	
	cout<<"Numero de palabras:\t"<<numWords<<endl;
	string tmp = "";
	while(tmp!="0")
	{
		cin>>tmp;
		cout<<"Esta:\t"<<dFile[tmp]<<endl;
	}
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
