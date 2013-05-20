#include"adverbio.h"

int main()
{
	string nameFile = "";
	cout<<"Ingrese el nombre del archivo"<<endl;
	cin>>nameFile;
	Adverbio adv(nameFile);
	//adv.openFile();
	adv.loadAdverbs();
	cout<<"Se leyeron: "<<adv.getNumLines()-1<<"\t lineas."<<endl;
	adv.start();
	return 0;
}
