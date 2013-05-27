#include"adverbio.h"

Adverbio::Adverbio(string name)
{
	nameFile = name;
	numLines = numWords = 0;
	for(int i=0;i<5;i++)
	{
		nAdverbios.push_back(0);
	}
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
			//cout<<tmp<<endl;
			int tipo = tmp[1] - '0';
			int size = tmp.size();
			for(int i=4;i<size-1;i++)
			{
				string word = "";
				while(tmp[i] !=',' && i<size-1)
				{
					word += tmp[i++];
				}
				//cout<<word<<"\ttipo:\t"<<tipo<<endl;
				Adverb advTmp(word,tipo);
				list.push_back(advTmp);
			}
		}
	}
	listAdverbios.close();
}

/*
void Adverbio::count_adverbs( const blocked_range<size_t> & r ){
     for(size_t i = r.begin(); i != r.end(); ++i )
         nAdverbios[list[i].getTipo()-1] += dFile[list[i].getAdverbio()];
}

void Adverbio::countAdverbs()
{
	parallel_for( blocked_range<size_t>(1,10), count_adverbs );
}
*/

void Adverbio::countAdverbs()
{
	int size = list.size();
	for(int i=0;i<size;i++)
	{
		nAdverbios[list[i].getTipo()-1] += dFile[list[i].getAdverbio()];
	}
}


void Adverbio::getNAdverbios()
{
	int size = nAdverbios.size();
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
	
	cout<<"Numero de palabras:\t"<<numWords<<endl;
	/*string tmp = "";
	while(tmp!="0")
	{
		cin>>tmp;
		cout<<"Esta:\t"<<dFile[tmp]<<endl;
	}*/
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

void Adverbio::giveValues(map<string,int> &dFile1,vector<Adverb> &list1,vector<int> &nAdverbios1)
{
	dFile1 = dFile;
	list1 = list;
	nAdverbios1 = nAdverbios;
}
