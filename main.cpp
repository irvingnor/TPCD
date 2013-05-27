#include"adverbio.h"

map<string,int> dFile1;
vector<Adverb> list1;
vector<int> nAdverbios1;

struct Average {
    void operator()( const blocked_range<int>& range ) const {
        for( int i=range.begin(); i!=range.end(); ++i )
            nAdverbios1[list1[i].getTipo()-1] += dFile1[list1[i].getAdverbio()];
    }
};

int main()
{
	task_scheduler_init init;
	string nameFile = "";
	cout<<"Ingrese el nombre del archivo"<<endl;
	cin>>nameFile;
	Adverbio adv(nameFile);
	adv.loadAdverbs();
	adv.openFile();
	cout<<"Se leyeron: "<<adv.getNumLines()-1<<"\t lineas."<<endl;
	adv.start();
	adv.giveValues(dFile1,list1,nAdverbios1);
	Average avg;
	parallel_for( blocked_range<int>( 1, list1.size() ), avg );
	
	int size = nAdverbios1.size();
	for(int i=0;i<size;i++)
	{
		cout<<"Existen\t"<<nAdverbios1[i]<<"\tde tipo "<<i+1<<endl;
	}
	//adv.countAdverbs();
	//adv.getNAdverbios();
	return 0;
}
