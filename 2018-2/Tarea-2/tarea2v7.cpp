#include <iostream>
#include <vector>

using namespace std;

vector<int> countandSay(vector<int> lass,int n)
{
	int l,counter =1;
	vector <int> ssal,ds;
    lass.push_back(1); 
    lass.push_back(1);

	ssal = lass;
	ds = ssal;
	lass.clear(); //borra todos los elementos que contiene el vector sobre el cual se harán push back los valores posteriores de la secuencia

	vector<int>::iterator it=ssal.begin();

	for(it;it<ssal.end();it++)
            {
				if(*(it)==*(it+1) && (it)!=ssal.end()-1)
                    /*Busca coincidencias entre el valor y el valor posterior a este, haciendo la salvedad de que no se haga esta evaluacion
                    si es que se ha llegado al valor previo al termino del vector*/
                {
                    counter++;
                }
                else if(it==ssal.end()-1) //en caso contrario, haz una copia de los elementos almacenados en el vector, borra el vector actual
                {   /*si es que se llega al final del vector, se debe hacer lo siguiente*/
                    lass.push_back(counter);
                    lass.push_back(*it);
                    counter=1; //vuelve el contador a uno luego de haber llegado al termino luego de recorrer del vector
                    continue;
                }
            }
    ssal=lass; /*la finalidad de este vector era que se pudiera almacenar una copia de los valores que se empujaron al vector
    es decir, 21 en el caso de la tercera iteracion, o 1211 en el caso de la cuarta, sin embargo, no lo pude hacer. Se me ocurre que de alguna manera, la copia
    de este vector, debía ir fuera de esta función, fuera del for.*/
    return lass;
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
		cout<<"\nL"<<j<<": ";
        if(j==1)
        {
            for(auto x:lass){cout<<x;}
            lass.clear();
        }
        else if(j==2)
        {
            lass.push_back(11);
            for(auto x:lass){cout<<x;}
            lass.clear();
        }
        else
        {

		ds = countandSay(lass,j);
        for(auto x:ds){cout<<x;}
        }

    }

	return 0;
}
