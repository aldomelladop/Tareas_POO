#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

int factorial(int largol1);
void permutar(list<int>l1,int factorial);
//void quitarceros();
void propiedad();

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

/*
void quitarceros()
{
    long long int counter=0;
    int largoc1=0,temp_sc=0;
	string temp;
    list<string> c1;
    
    ifstream entrada("salida.txt");
    ofstream salida("salida_sin_ceros.txt");

    cout<<"\n";

    while(entrada >> temp)
	{			

		if(temp[0]!='0')
		{
//		cout<<"temp: "<<temp<<endl;
		c1.push_back(temp);
		salida<<temp;
		salida<<"\n";
		}
	counter++;
	}
	entrada.close();
	salida.close();

// Hasta acá, los números están calculados, almacenados y también filtrados de aquellos que tienen por primer dígito un cero
	cout<<"La cantidad de números pandigitales, para números del 0-9, es: "<<counter<<endl;
	propiedad();
}
*/

void propiedad()
{
	int d2=0,d3=0,d4=0,d5=0,d7=0,d11=0,d13=0,d17=0;
	int dv2=0,dv3=0,dv5=0,dv7=0,dv11=0,dv13=0,dv17=0;
	long long int temp;
	list<long long int> prop,listafinal;
	//list<long long int>::iterator it= prop.begin();

	ifstream entrada("salida.txt");
	ofstream salidaf("propiedad.txt");

	while(entrada >> temp)
	{			
		prop.push_back(temp);
		list<long long int>::iterator it= prop.begin();
		
		for(it;it!=prop.end();it++)	
		{
			d2 = (*(it+1))+ (*(it+2))+ (*(it+3));
			d3 = (*(it+2))+(*(it+3))+(*(it+4));
			d5 = *(it+3)+*(it+4)+*(it+5);
			d7 = *(it+4)+*(it+5)+*(it+6);
			d11 = *(it+5)+*(it+6)+*(it+7);
			d13 = *(it+6)+*(it+7)+*(it+8);
			d17 = *(it+7)+*(it+8)+*(it+9);

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
		


	}
	entrada.close();
	salidaf.close();
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