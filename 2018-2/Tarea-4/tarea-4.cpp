#include <iostream>
#include <iomanip>
#include <fstream>
#include <tuple>
#include <list>

using namespace std;

list<float> leerelementos(list<float> v1);
void llenaelista(list<float> l1);
void imprimelista(list<float> l1);


tuple<list<float>,list<float>,list<float>> leerelementos()
{
	tuple<list<float>,list<float>,list<float>> var;
	float t1,t2,p;
	list<float> tiempo1,tiempo2,priority;
	ifstream in("eventos.txt");

	while(!in.eof())
	{
		in>>t1;
		tiempo1.push_back(t1);
		in>>t2;
		tiempo2.push_back(t2);
		in>>p;
		priority.push_back(p);
	}
	get<0>(var) = tiempo1;
	get<1>(var) = tiempo2;
	get<2>(var) = priority;
	in.close();

return var;
}

void imprimelista(list<float> v2)
{
	list<float>::iterator it;
	it = v2.begin();
	
	for(auto x:v2)
	{cout<<setprecision(8)<<x<<"\n";}
}


int main()
{
	tuple<list<float>,list<float>,list<float>> v;

	v = leerelementos();

	/* Hasta este punto, se han extraído los elementos del archivo de texto "eventos.txt", se ha almacenado cada columna, con sus respectivos datos
	en listas que llevan por nombre:

	tiempo1  -> asociada a la primera columna;
	tiempo2  -> asociada a la segunda columna;
	prioridad-> asociada a la tercera columna;
	
	hecho esto, se pueden asignar los valores para poder realizar el cálculo de lo requerido en el problema.

	Consideraciones: cabe mencionar que en la función imprime lista, se seteó una precisión de 8 cifras, a fin de evitar problemas por truncamiento en la cantidad de dígitos.
	*/	

	return 0;

}