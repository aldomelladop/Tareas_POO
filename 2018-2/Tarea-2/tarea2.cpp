#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> lass(int n)
{
	int count=1; //Inicializado en 1 pues se considera el primer elemento, es decir, para 111 sería, a la segunda ocurrencia, un count=2;
	vector <int> lass, ssal;
	vector <int>::iterator it=lass.begin();
	vector <int>::iterator it1=ssal.begin();
	lass.push_back(1);

for(int k=1;k<=n;k++) //Avanza en los niveles de la secuencia.
{
	for(it;it!=lass.end();it++)
		{
			if((it)=lass.end()) //Si es que he llegado al final del nivel de la secuencia, evaluar si es que el penultimo dígito es igual al ultimo
			{
				if(*(it-1)==*(it))
				{
					cou
				}	
			}
			while(*it==*(it+1))
			{
				count++;
			}
            ssal=lass;
            lass.clear();
            lass.push_back(count);
            lass.push_back(*it1);
            it1++;
		}
	}
return lass;
}


int main()
{
	int n;
	vector<int> ds;
	vector<int>::iterator it=ds.begin();

	cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea que desea mostrar: ";
	cin>>n;

	for(int j=0;j<=n;j++)
	{	
		lass(j);
		cout<<"La línea "<<j<<" tiene por secuencia: ";   	
	}
	return 0;
}
