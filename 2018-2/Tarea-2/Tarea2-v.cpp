#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> lass(int n)
{
	vector <int> lass, ssal;
	vector <int>::iterator it=ssal.begin();
	vector <int>::iterator it1=lass.begin();
	lass.push_back(1);

	ssal = lass;

	for(it;it!=ssal.end();it++)
		{
	int	counter = 1; //Inicializamos en 1 el contador, a contar de la segunda ocurrencia será 2.
			if(*(it)==*(it+1)) //Si es que el valor actual, es igual al siguiente, añade uno al contador
			{
				counter++;
			}
			else if(*(it)!=*(it+1)) //en caso contrario, haz una copia de los elementos almacenados en el vector, borra el vector actual
			{
				lass = ssal;
    	        ssal.clear();
        	    lass.push_back(counter);
            	lass.push_back(*it);
            }
            else
            {
            	lass.push_back(counter);
            	lass.push_back(*it);
            }
			ssal=lass;
    	    lass.clear();
        	lass.push_back(counter);
            lass.push_back(*it1);
            it1++;
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

	for(int j=1;j<=n;j++)
	{
		ds  = lass(j);
		cout<<"La línea "<<j<<" tiene por secuencia: ";
		for(it;it!=ds.end();it++)
		{
			cout<<*it;
		}
	}
	return 0;
}
