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
int divisible(int modulo);

int divisibles(int modulo)
{
	int temp,j=0;
	long int aux=0,suma;
	int dv2=0,dv3=0,dv5=0,dv7=0,dv11=0,dv13=0,dv17=0;

	if(modulo==2)
	{
		ifstream entrada("propiedad2.txt");
		while(entrada>>temp)
		{	
			aux = temp;
			if((aux%modulo)==0)
				{j++;
		}
		entrada.close();
	}
	else if(modulo==3)
	{
		ifstream entrada("propiedad3.txt");
		
		while(entrada>>temp)
		{
			aux = temp;
			if((aux%modulo)==0)
				{j++;}
		}
	}
	else if(modulo==3)
	{
		ifstream entrada("propiedad3.txt");
		
		while(entrada>>temp)
		{
			aux = temp;
			if((aux%modulo)==0)
				{j++;}
		}
	}
	else if(modulo==5)
	{
		ifstream entrada("propiedad5.txt");
		
		while(entrada>>temp)
		{
			aux = temp;
			if((aux%modulo)==0)
				{j++;}
		}
	}
	else if(modulo==7)
	{
		ifstream entrada("propiedad7.txt");
		
		while(entrada>>temp)
		{
			aux = temp;
			if((aux%modulo)==0)
				{j++;}
		}
	}
	else if(modulo==11)
	{
		ifstream entrada("propiedad11.txt");
		
		while(entrada>>temp)
		{
			aux = temp;
			if((aux%modulo)==0)
				{j++;}
		}
	}
	else if(modulo==13)
	{
		ifstream entrada("propiedad13.txt");
		
		while(entrada>>temp)
			{
				aux = temp;
				if((aux%modulo)==0)
					{j++;}
			}
	}
	else if(modulo==17)
	{
		ifstream entrada("propiedad17.txt");
		
		while(entrada>>temp)
		{
			aux = temp;
			if((aux%modulo)==0)
				{j++;}
		}
	}	
	return j;
}

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
	propiedad();
}

void propiedad()
{
	vector<int>vector1;
	string temp;
	long long int aux;
	int d2=0,d3=0,d4=0,d5=0,d7=0,d11=0,d13=0,d17=0,suma=0;

	list<long long int> prop,listafinal;

	ifstream entrada("salida.txt");
	
	while(entrada >> temp)
	{			
		aux = stoi(temp);
		vector1 = int2vector(aux);
		
		ofstream salida2("propiedad2.txt");
		ofstream salida3("propiedad3.txt");
		ofstream salida5("propiedad5.txt");
		ofstream salida7("propiedad7.txt");
		ofstream salida11("propiedad11.txt");
		ofstream salida13("propiedad13.txt");
		ofstream salida17("propiedad17.txt");
		
		vector<int>::iterator it = vector1.begin();
		
		for(it;it!=vector1.end();it++)		
		{
			salida2<<(*(it+1))<<(*(it+2))<<(*(it+3));
			salida2<<"\n";
			salida3<<(*(it+2))<<(*(it+3))<<(*(it+4)); 
			salida3<<"\n";
			salida5<<(*(it+3))<<(*(it+4))<<(*(it+5));
			salida5<<"\n";
			salida7<<(*(it+4))<<(*(it+5))<<(*(it+6));
			salida7<<"\n";
			salida11<<(*(it+5))<<(*(it+6))<<(*(it+7));
			salida11<<"\n";
			salida13<<(*(it+6))<<(*(it+7))<<(*(it+8));
			salida13<<"\n";
			salida17<<(*(it+7))<<(*(it+8))<<(*(it+9));
			salida17<<"\n";
		}
	salida2.close();
	salida3.close();
	salida5.close();
	salida7.close();
	salida11.close();
	salida13.close();
	salida17.close();
	entrada.close();
	}
	vector<int> modulo={2,3,5,7,11,13,17};
	vector<int>::iterator itm = modulo.begin();
	for(itm;itm!=modulo.end();itm++)
	{
		cout<<"\nLa cantidad de números divisibles por "<<*itm<<" es: "<<divisibles(*itm)<<endl;
	}
	cout<<"\nLa suma de los números pandigitales que cumplen la propiedad: "<<suma<<endl;
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