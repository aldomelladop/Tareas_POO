#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void slas(vector<int> lass)
{
	vector <int> ssal,ds;
	ssal = lass;
	lass.clear();

	//cout<<"imprimiendo ssal ";
	//for(auto x:ssal){cout<<x;}
	//cout<<"\n";

	vector <int>::iterator it=ssal.begin();

	int	counter = 1; //Inicializamos en 1 el contador, a contar de la segunda ocurrencia será 2.

	for(it;it<=ssal.end();it++)
    {

        if(*(it)==*(it+1) && (it)!=ssal.end()-1)
		{
            cout<<"\nentra al if"<<endl;
            cout<<"valor del iterador: "<<*it<<endl;
            counter++;
        }
		else if(it==ssal.end()) //en caso contrario, haz una copia de los elementos almacenados en el vector, borra el vector actual
		{
            cout<<"\nEntra al else if"<<endl;
            cout<<"valor del iterador: "<<*it<<endl;
            lass.push_back(counter);
            lass.push_back(*it);
            counter=1;
        }
        else
        {
            cout<<"Entrando al else"<<endl;
            {
                cout<<"valor del iterador: "<<*it<<endl;
                lass.push_back(*it);
            }
        }
    }
    ds = lass;
    for(auto x:ds){cout<<x;}
}

int main()
{
	int n ;
	vector <int> lass; //lass = look and say sequence
    lass.push_back(1);

	cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea mostrar: ";
	cin>>n;

    cout<<"\nEs la secuencia correspondiente a la línea: \n"<<endl;

	for(int j=1;j<=n;j++)
	{
		cout<<"\nL"<<j<<" ";
        slas(lass);
    }
	return 0;
}
