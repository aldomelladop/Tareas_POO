#include <list>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int len1,len2,len3,lens=0,cont=0,m=0,aux=0,C=0,i=0,fibo=0,cont1=0; //declaración de variables a utilizar
    list<int> suma,L1,L2; //declaración de listas
    list<int>:: iterator it1,it2,it3; //declaración de iteradores

    L1.push_back(1);
    L2.push_back(1);
    //inicializamos la lista en f0 = 1, que corresponden a los primeros valores de la sucesión.

	it1 = L1.begin();
	it2 = L2.begin();
	len1= L1.size();
	len2= L2.size();
	/*con los iteradores y sus largos respectivos, definimos la condición de que en el ciclo while, apenas se alcance en la lista L2, un largo igual o mayor a los 1000 dígitos se detenga.*/

	while(len2<=1000)
	{
        cont = 0;
        cont1++;
		for(it2=L2.begin(); it2!=L2.end();it2++)
		{
            aux = *it1 + *it2 + C;
			m = aux%10;cont++;

			if (aux<10)
			{suma.push_back(aux);C = 0;}

			else

            {suma.push_back(m);C = 1;}

            if(C==1 && L2.size()==cont)
            {suma.push_back(C);C  = 0;}
            it1++;
        }

        L1.clear();
		L1=L2;
		it1 = L1.begin();
		len1= L1.size();

		L2.clear();
		L2 = suma;
		len2 = L2.size();
		suma.clear();

		if (len2>len1)
		{
        	for (i=0;i<len3;i++)
        	{L1.push_back(0);}
		}

        if (len2>1000)
//        if (len2>= 1000 && cont1>4784)

        {cout<<"1000 dígitos alcanzados en el índice:  "<<cont1<<endl;break;}
    }
    return 0;
}