#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

int factorial(int largol1);
void permutar(list<int>l1,int factorial);
//void quitarceros();
void propiedad();
list<int> num2vec(long long int value);

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
		cout<<"La cantidad de números pandigitales, para números del 0-9, es: "<<j<<endl;
	//quitarceros();
}

/*void quitarceros()
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
	long long int temp;
	list<long long int> prop,listafinal;

	ifstream entrada("salida.txt");

	while(entrada >> temp)
	{			
		prop.push_back(temp);
	}
	entrada.close();

	list<long long int>::iterator itfinal= prop.begin();

	for(itfinal;itfinal!=prop.end();itfinal++)
	{
		num2vec(*itfinal);
	}
}

int main()
{
	long int largol1,perm=0;
	list<int>l1;

	l1 = {0,1,2,3,4,5,6,7,8,9};

	largol1 = l1.size();
	perm = factorial(largol1);

	permutar(l1,perm);
	return 0;
}
