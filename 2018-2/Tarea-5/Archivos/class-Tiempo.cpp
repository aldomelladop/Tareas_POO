#include<iostream>
#include<stdlib.h>

using namespace std;

class Tiempo
{
	private:
		int horas;
		int minutos;
		int segundos;	
	public:
		Tiempo(int,int,int);//constructor 1;
		Tiempo(int);
		void mostrarhora();
};

//Constructor 1
Tiempo::Tiempo(int _horas, int _minutos, int _segundos)
{
	horas = _horas;
	minutos = _minutos;
	segundos = _segundos;
}

//Constructor 2
Tiempo::Tiempo(int _todojunto)
{
	horas = _todojunto/3600;
	minutos = _todojunto/60-horas*60;
	segundos = _todojunto%60;
}

void Tiempo::mostrarhora()
{
	cout<<"La hora es: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
}
int main()
{
	Tiempo t1 = Tiempo(22,29,11);
	t1.mostrarhora();

	Tiempo t2= Tiempo(81542);
	t2.mostrarhora();
	return 0;
}