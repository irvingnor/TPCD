#include"adverbio.h"

int main()
{
	Adverbio adv("archivo.txt");
	adv.openFile();
	cout<<"Se leyeron: "<<adv.getNumLines()-1<<"\t lineas."<<endl;
	adv.printBuffer();
	return 0;
}
