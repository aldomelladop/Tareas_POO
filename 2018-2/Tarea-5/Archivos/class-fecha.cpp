#include<iostream>
#include<stdlib.h>

using namespace std;

class fecha
{
	private:
		int dia;
		int mes;
		int anio;
	public:
		fecha(int,int,int);
		fecha(long);
		void mostrarfecha();
};

//constructor 1
fecha::fecha(int _dia, int _mes, int _anio)
{
	dia  = _dia;
	mes  = _mes;
	anio = _anio;
}
//constructor 2
fecha::fecha(long _diamesanio)
{
	anio = int(_diamesanio/10000);
	mes  = int((_diamesanio-(anio*10000))/100);
	dia  = int(_diamesanio-(anio*10000)-(mes*100));
}

void fecha::mostrarfecha()
{
	cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main()
{
	fecha f1 = fecha(15,10,2018);
	f1.mostrarfecha();

	fecha f2 = fecha(20181015);
	f2.mostrarfecha();
	return 0;
}