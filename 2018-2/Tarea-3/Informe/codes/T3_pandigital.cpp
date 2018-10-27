#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream> 
#include <list>
#include <vector>
#include <math.h>

using namespace std;

int factorial(int largol1);
void permutar(list<int>l1,int factorial);
void propiedad();
vector<int> int2vector(int num);

vector<int> int2vector(int num) //Creamos una funcion para convertir de entero a vector
{
        int n = num;
        vector<int> v1;

        int r = 0, aux = 0;
        int d = 10;

        while(r!= n)  //Este while tiene como funcion, contar la cantidad de cifras que tiene n
        {
            r = n%d;
            d = d * 10;
            aux++;
        }
        aux--;

        int cif = aux;
        d = pow(10,cif);
        r = 0;

        while( cif >= 0)  //este while guarda cifra por cifra en el vector
        {
            int num = n / d;
            r = n % d;
            n = r;
            d /= 10;
            v1.push_back(num);
            cif--;
        }
        return v1;
}

int factorial(int largol1)
{
	int factorial=1;

	for(int i=1;i<=largol1;i++)
	{

		factorial=factorial*i;
	}
	return factorial;
	
}

void permutar(list<int>l1,int factorial)
{
	int j=0;
	list<int>l2;
	l2 = l1;
	
	ofstream salida("salida.txt");

	while(j<factorial)
	{
        list<int>::iterator it=l2.begin();

        for(auto x:l2)
			{
                salida<<x;
            }
        salida<<"\n";

        next_permutation(l2.begin(),l2.end());
		j++;
	}
	salida.close();
//	quitarceros();
	propiedad();
}

void propiedad()
{
	vector<int>vector1;
	string temp;
	long long int aux;
	unsigned int suma;
	int d2=0,d3=0,d4=0,d5=0,d7=0,d11=0,d13=0,d17=0;
	int dv2=0,dv3=0,dv5=0,dv7=0,dv11=0,dv13=0,dv17=0;

	list<long long int> prop,listafinal;

	ifstream entrada("salida.txt");
	ofstream salidaf("propiedad.txt");

	while(entrada >> temp)
	{			
		aux = stoi(temp);
		vector1 = int2vector(aux);
		
		vector<int>::iterator it = vector1.begin();
		
		for(it;it!=vector1.end();it++)		
		{
			d2 = (*(it+1))+(*(it+2))+(*(it+3));
			d3 = (*(it+2))+(*(it+3))+(*(it+4));
			d5 = (*(it+3))+(*(it+4))+(*(it+5));
			d7 = (*(it+4))+(*(it+5))+(*(it+6));
			d11 =(*(it+5))+(*(it+6))+(*(it+7));
			d13 =(*(it+6))+(*(it+7))+(*(it+8));
			d17 =(*(it+7))+(*(it+8))+(*(it+9));

			if(d2%2!=0)
			{
				dv2++;
			}
			else if(d3%3!=0)
			{
				dv3++;
			}
			else if(dv5%5!=0)
			{
				dv5++;
			}
			else if(d7%7!=0)
			{
				dv7++;
			}
			else if(d11%11!=0)
			{
				dv11++;
			}
			else if(d13%13!=0)
			{
				dv13++;
			}
			else if(d17%17!=0)
			{
				dv17++;
			}
	}

	entrada.close();
	salidaf.close();
}
	suma =  d2+d3+d5+d7+d11+d13+d17;
	cout<<"\nLa cantidad de números divisibles por 2 es: "<<dv2<<endl;
	cout<<"La cantidad de números divisibles por 3 es: "<<dv3<<endl;
	cout<<"La cantidad de números divisibles por 5 es: "<<dv5<<endl;
	cout<<"La cantidad de números divisibles por 7 es: "<<dv7<<endl;
	cout<<"La cantidad de números divisibles por 11 es: "<<dv11<<endl;
	cout<<"La cantidad de números divisibles por 13 es: "<<dv13<<endl;
	cout<<"La cantidad de números divisibles por 17 es: "<<dv17<<endl;
	cout<<"La suma de los números pandigitales que cumplen la propiedad: "<<suma<<endl;
}


 int main()
{
	long int largol1,perm=0;
	list<int>l1;

	l1 = {0,1,2,3,4,5,6,7,8,9};

	largol1 = l1.size();
	perm = factorial(largol1);
	cout<<"La cantidad de números pandigitales, para números del 0-9, es: "<<perm<<endl;

	permutar(l1,perm);
	return 0;
}