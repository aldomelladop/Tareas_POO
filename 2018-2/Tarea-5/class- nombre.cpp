//Clases en C++
#include<iostream>
#include<stdlib.h>

using namespace std;

class persona
{
	private:
		int edad;
		string nombre;
	public:
		persona(int, string);
		void leer();
		void correr();
};

persona::persona(int _edad,string _nombre)
{
	edad = _edad;
	nombre = _nombre;
}

void persona::leer()
{
	cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
}

void persona::correr()
{
	cout<<"soy "<<nombre<<" tengo "<<edad<<" y estoy corriendo una maratón"<<endl;
}

int main()
{
	persona p1 = persona(20,"alejandro");
	persona p2 = persona(20,"constanza");
	p1.correr();
	p1.leer();
	p2.leer();
	return 0;
}