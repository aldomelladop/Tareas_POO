#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;
int factorial(int largol1);
void permutar(list<int>l1,int factorial);
void quitarceros();

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
		/*
		if((j%10)==0)
		{cout<<"\n"<<j;}
		*/
	}
	salida.close();
	quitarceros();
}

void quitarceros()
{
    long long int counter=0;
    int largoc1=0,temp_sc=0;
	string temp;
    list<string> c1;
    
    ifstream entrada("salida.txt");
    ofstream salida("rev_salida.txt");

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
	}
	entrada.close();
	salida.close();

/** Hasta acá, los números están calculados, almacenados y también filtrados de aquellos que tienen por primer dígito un cero**/
/*
	ifstream entrada_ant("rev_salida.txt");
	ofstream salida_nueva("sinceros.txt");

	while(entrada_ant>>temp_sc)
	{	
	//	cout<<"temp_sc: "<<temp_sc<<endl;
		salida_nueva<<temp_sc;
		salida_nueva<<"\n";
		counter++;
	}
*/
/*	
	{
	list<char>::iterator it=c1.begin();

	for(it;it!=c1.begin();it++)
	{
		list<int> a;
		a.push_back(*it);
		
		largoc1 =a.size();

		if(largoc1=largol1)
		{
		salida<<*it;
		}
	}
*/
	/*for(auto x:c1)
	{	
		largoc1 = c1.size();
		if(largoc1==largol1)
		{salida<<x;}

	cout<<"C"<<count<<": "<<x<<endl;count++;
	}
	}
	*/
	entrada.close();
	salida.close();
	entrada_ant.close();
	salida_nueva.close();
	cout<<"La cantidad de números pandigitales, para números del 0-9, es: "<<counter<<endl;
}

 int main()
{
	long int largol1,perm=0;
	list<int>l1;
//	l1 = {0,1,2,3,4,5,6,7,8,9};
	l1 = {0,1,2,3,4,5,6,7,8,9};
	largol1 = l1.size();

	perm = factorial(largol1);
	cout<<"Resultado Factorial "<<perm;
	permutar(l1,perm);
	return 0;
}
