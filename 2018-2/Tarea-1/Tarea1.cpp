#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector<int> num,prueba;

/*Si se declara global el vector<int> num, se evita tener que definir la función como sigue; vector<int> num2vec(vector<int> num, int value)*/
vector<int> num2vec(int value)
{
   const int base = 10;
   int digit = value % base;

   if ( value /= base )
   {
   	 num2vec(value);
   }

   num.push_back(digit); /* Si va anotada acá, es similar a que se aplicara un reverse */
   
   return num;
}

vector<int> sumofvect(vector<int> v1,vector<int>v2)
{	
	int aux,c;
    vector<int> suma;
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
                c = aux/10;             }
            else if((c == 1)&& (it2  == it1))
            {
                suma.push_back(c);
                c = 0;
            }
            it1++;
            it2++;
        }

    return suma;
}


vector<int> prodVect(vector<int> v1,vector<int> v2)
{
	
    vector<int> producto;
    //vector<int> v1,v2,producto;
		
	/* Se optó por hacer este reverse puesto que la función push_front() no está disponible para el contenedor del tipo vector, de modo que,
	si se hace el reverse, se puede trabajar con la funciín push_back()*/

	reverse(v1.begin(),v1.end());
    reverse(v2.begin(),v2.end());

    vector<int>::iterator it1=v1.begin();
	vector<int>::iterator it2=v2.begin();

	int mult,m,c=0,x=1;
    vector<int> aux = num2vec(0);
    
    while(v2.size()<v1.size())
    {
    	v1.push_back(0);
    }

    for(it2=v2.begin();it2!=v2.end();it2++)
    {

        for(it1=v1.begin();it1!=v1.end();it1++)
        {
            mult = ((*it2)*(*it1)+ c);
            aux = sumofvect(aux,num2vec((mult*(pow(10,x)))));

            if(mult < 10)
            {
                c = 0;
            }
            else
            {
            	m = mult%10; /* 121%10 = 1 */
            	aux.push_back(m);
            	c = (mult/10); /*121/10 = 12 */
            }
        }
    }

            x++;   //k*= 10; /* Amplifica sucesivamente, los valores obtenidos desde las multiplicaciones de unidades, decenas y centenas del numero*/

    if (c > 0)
    {
        aux.push_back(c);
    }
   return aux;
}

int main()
{
    int sum=0,k=0;
	vector<int> factorial;
    vector<int>::iterator it;

    factorial = num2vec(1);

    it  = factorial.begin();

    for(int i = 2; i<=10;i++)
    {
        factorial = prodVect(factorial,num2vec(i)); //iteramos la multiplicacion entre vectores
        k++;
    }

    
    it =factorial.begin();

    cout<<"Los dígitos de 1000! son: "<<endl;

    for(it;it!=factorial.end();it++)
    {
        cout<<*it<<" ";
    }
    
    cout<<"\n\n1000! tiene "<<k<<" dígitos. "<<endl;

    for(it;it!=factorial.end();it++)
    {
        cout<<"el valor de *it es:"<<*it<<endl;
        sum+=*it;
    }

    cout<<"\nLa suma de sus digitos es: "<<sum<<endl;    

	return 0;
}