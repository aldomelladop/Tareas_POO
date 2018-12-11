#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

vector <int> lass;

vector<int> slas(int c)
{
	vector <int> ssal;
	ssal = lass;
	lass.clear();

	vector <int>::iterator it=ssal.begin();
	vector <int>::iterator it1=lass.begin();

	for(it;it<ssal.end();it++)
	{
        cout<<" "<<*it;
	}

    //cout<<"\nperrito bailarín"<<endl;

	for(it;it<=ssal.end();it++)
		{
    //cout<<"entrando al primer for"<<endl;

	int	counter = 1; //Inicializamos en 1 el contador, a contar de la segunda ocurrencia será 2.
			//if(*(it)==*(it+1)) //Si es que el valor actual, es igual al siguiente, añade uno al contador
			if(*(it)==*(it+1) && (it+1)!=ssal.end()) //Si es que el valor actual, es igual al siguiente, añade uno al contador
			{
                cout<<"\nentra al if"<<endl;
				counter++;
			}
			else
				//if(*(it)!=*(it+1) || it==ssal.end()) //en caso contrario, haz una copia de los elementos almacenados en el vector, borra el vector actual
			{
                cout<<"\nentra al else if"<<endl;
                lass.push_back(counter);
            	lass.push_back(*it);
            }
            /*
            //cout<<"Genera una copia de la secuencia resultante"<<endl;
			ssal=lass;
    	    lass.clear();
        	lass.push_back(counter);
            lass.push_back(*it);
            //it1++;
            */
        }
return lass;
//
}

int main()
{
	int n;
	lass.push_back(1);

	cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea que desea mostrar: ";
	cin>>n;

    cout<<"\nEs la secuencia correspondiente a la línea: \n"<<endl;

	for(int j=1;j<=n;j++)
	{
        vector<int> ds;
        vector<int>::iterator it2=ds.begin();

		ds  = slas(j);
		cout<<"L"<<j<<endl;

		for(auto x:ds){cout<<x;}
	}

	return 0;
}
