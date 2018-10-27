#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector<int> num;

vector<int> num2vec(vector<int> vector, int value)
{
   const int base = 10;
   int digit = value % base;

   if ( value /= base )
   {
   	 num2vec(num,value);
   }

   num.push_back( digit ); /* Si va anotada acá, es similar a que se aplicara un reverse */
   
   return num;
}


int sumofvect(vector<int> v1,vector<int>v2)
{	
	int Suma,aux,c;
	vector<int>suma;
    vector<int>::iterator it1=v1.begin();
    vector<int>::iterator it2=v2.begin();

    while(v2.size()<v1.size())
    {
    	v1.push_back(0);
    }

    for(int i = 0; i < v1.size();i++)
        {

            aux = (*it1)+(*it2)+c;

            if(aux < 10)
                {
                    suma.push_back(aux);
                    c = 0;
                }
            else if (aux >= 10)
            {
                suma.push_back(aux%10); /*Hace un push_back() del valor de decenas*/
                c = aux/10; 
            }
            else if((c == 1)&& (it2  == it1))
            {
                suma.push_back(c);
                c = 0;
            }
            it1++;
            it2++;
        }
    return Suma;
}


vector<int> prodVect(vector<int> vec1,vector<int> vec2)
{
	vector<int> v1,v2,producto;
		
	/* Se optó por hacer este reverse puesto que la función push_front() no está disponible para el contenedor del tipo vector, de modo que,
	si se hace el reverse, se puede trabajar con la funciín push_back()*/

	reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());

    vector<int>::iterator it1=v1.begin();
	vector<int>::iterator it2=v2.begin();

	int mult,m;
	int d = 1;
    vector<int> aux = num2vec(num,0);
    int c = 0;
    
    while(v2.size()<v1.size())
    {
    	v1.push_back(0);
    }

    for(it2=v2.begin();it2!=v2.end();it2++)
    {
        for(it1=v1.begin();it1!=v1.end();it1++)
        {
            mult = ((*it2)*(*it1)+ c);
            //aux = sumofvect(aux,int2vector((sumint*d)));

            if(mult < 10)
            {
                c = 0;
            }
            else
            {
            	m = mult%10;
            	aux.push_back(m);
            	c = (mult/10);
            }
        }
    }

    if (c > 0)
    {
        aux.push_back(c);
    }
   return aux;
}

vector<int> factorial(vector<int>v1,int num)
{

vector<int> v2,aux;

v2 = num2vec(num);

aux = prodVect(v1,v2);

return aux;
}
int main()
{
	vector<int> f, factorial;

	factorial.push_back(1);

	for(int j=2;j<1001;j++)
	{
	factorial = factorial(factorial,j);
	}

	vector<int>::iterator it = factorial.begin();

	int y = 0; 
	for(auto x:factorial)
	{

		y = x + y;
	}
	
	return 0;
}