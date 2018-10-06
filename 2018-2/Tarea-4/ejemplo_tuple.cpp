#include <iostream>
#include <fstream>
#include <utility>
#include <tuple>
#include <list>

using namespace std;

list<float> leerelementos(list<float> v1);
void llenaelista(list<float> l1);
void imprimelista(list<float> l1);


tuple<list<float>,list<float>,list<float>> leerelementos()
{
	
	list<float> tiempo1,tiempo2,priority;
	tuple<list<float>,list<float>,list<float>> variables;

	for(float i=0.1;i<10;i++)
	{
		get<0>(variables).push_back(i);
	}

	for(float j=0.2;j<10;j++)
	{
		get<1>(variables).push_back(j);
	}

	for(float k=0.3;k<10;k++)
	{
		get<2>(variables).push_back(k);
	}
	/*
	tiempo1 = get<0>(variables);
	tiempo2 = get<1>(variables);
	priority = get<2>(variables);
	*/
return variables;
}

void imprimelista(list<float> v2)
{
	list<float>::iterator it;
	it = v2.begin();
	
	for(auto x:v2)
	{cout<<x<<" ";}
}

int main()
{

	tuple<list<float>,list<float>,list<float>> tupla2;
	list<float> tiempo1,tiempo2,prioridad;

	tupla2 = leerelementos();

	tiempo1= get<0>(tupla2);
	tiempo2= get<1>(tupla2);
	prioridad=get<2>(tupla2);

	imprimelista(tiempo1);
	cout<<"\n";
	imprimelista(tiempo2);
	cout<<"\n";
	imprimelista(prioridad);
	cout<<"\n";
	return 0;
}