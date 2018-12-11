#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void slas(vector<int> lass)
{
	vector <int> ssal,ds;
	ssal = lass;
	lass.clear();
    ds.clear();

	vector <int>::iterator it=ssal.begin();
/*
	for(it;it<ssal.end();it++)
	{
        cout<<" "<<*it;
	}
*/
	int	counter = 1; //Inicializamos en 1 el contador, a contar de la segunda ocurrencia será 2.
    cout<<"contador "<<counter<<endl;

	for(it;it<=ssal.end()-1;it++)
    {
        if(*(it)==*(it+1) && (it+1)!=ssal.end()) //Evita que en la iteración siguiente, se produzca que compare el ultimo elemento con el siguiente luego del ultimo
        {
            cout<<"\nentra al if"<<endl;
            cout<<"El valor del counter es: "<<counter<<endl;
            counter++;
        }
		else if(it==ssal.begin())
		{
            cout<<"Entra al else if: "<<endl;
            lass.push_back(*it);
		}
		else
		//if(*(it)!=*(it+1) || it==ssal.end()) //en caso contrario, haz una copia de los elementos almacenados en el vector, borra el vector actual
		{
            cout<<"Entra al else"<<endl;
            cout<<"El valor del iterador es "<<*it<<endl;
            cout<<"El valor del contador es: "<<counter<<endl;
            lass.push_back(counter);
           	lass.push_back(*it);
        }
    }
    ds = lass;
    for(auto x:ds){cout<<x;}
}

int main()
{
	int n;
	vector <int> lass; //lass = look and say sequence
    lass.push_back(1);

	cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea mostrar: ";
	cin>>n;

    cout<<"\nEs la secuencia correspondiente a la línea: \n"<<endl;

	for(int j=1;j<=n;j++)
	{
        /*
        vector<int> ds;
        vector<int>::iterator it2=ds.begin();
        */
		cout<<"\nL"<<j<<endl;
        slas(lass);
    }

	return 0;
}
