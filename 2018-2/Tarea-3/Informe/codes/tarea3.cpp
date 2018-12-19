#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <cstdlib>     /* strtoll */


using namespace std;

void propiedad(string l2);// se llama a la funcion debido a que como se concibio la solucion, propiedad depende de permutar y este depende de factorial.
void sumofList(list<int> l2);
list<int> strToList(string str);

int contador=0;
list<int> sumapandigital={0};


int factorial(int largol1)
{
	int factorial=1;
	for(int i=1;i<=largol1;i++)
	{
		factorial=factorial*i;
	}
	return factorial;
}

void permutar(string l1,int factorial)
{
	string l2;
	l2 = l1;

	string::iterator it=l2.begin();

	for(int j=0;j<factorial;j++)
	{
		next_permutation(l2.begin(),l2.end());
		propiedad(l2);
	}
}

void propiedad(string l2)
{
	list<int> aux;

	char d1=l2[0],d2=l2[1], d3=l2[2],d4=l2[3],d5=l2[4];
	char d6=l2[5],d7=l2[6], d8=l2[7],d9=l2[8],d10=l2[9];

	//Contadores
	int dv2=0,dv3=0,dv5=0,dv7=0,dv11=0,dv13=0,dv17=0;

	string n2={""},n3={""},n5={""},n7={""},n11={""},n13={""},n17={""};

	n2.push_back(d2);n2.push_back(d3);n2.push_back(d4);
	dv2  =  stoi(n2);

	n3.push_back(d3);n3.push_back(d4);n3.push_back(d5);
	dv3  =  stoi(n3);

	n5.push_back(d4);n5.push_back(d5);n5.push_back(d6);
	dv5  =  stoi(n5);

	n7.push_back(d5);n7.push_back(d6);n7.push_back(d7);
	dv7  =  stoi(n7);

	n11.push_back(d6);n11.push_back(d7);n11.push_back(d8);
	dv11  =  stoi(n11);

	n13.push_back(d7);n13.push_back(d8);n13.push_back(d9);
	dv13  =  stoi(n13);

	n17.push_back(d8);n17.push_back(d9);n17.push_back(d10);
	dv17  =  stoi(n17);

	int flag=0;

	if(dv2%2==0)
	{
		flag=1;
	}
	if(dv3%3==0 && flag==1)
	{
		flag=1;
	}
	if(dv5%5==0 && flag==1)
	{
		flag=1;
	}
	if(dv7%7==0 && flag==1)
	{
		flag=1;
	}
	if(dv11%11==0 && flag==1)
	{
		flag=1;
	}
	if(dv13%13==0 && flag==1)
	{
		flag=1;
	}
	if(dv17%17==0 && flag==1)
	{
		flag=1;
	}

	if(flag==1)
	{
		aux = strToList(l2);
		sumofList(aux);
		contador++;
	}
}

 void sumofList(list<int> l2)
{
  transform (l2.begin(), l2.end(), sumapandigital.begin(), sumapandigital.begin(),plus<int>());
}

list<int> strToList(string str)
{
	list<int> list1;
	int j=0,k=0;

	for(auto x:str)
	{
		k  = int(x-48);
		list1.push_back(k);
	}
	return list1;
}

 int main()
{
	string l1;
	int largol1,perm=0,suma=0;

	l1 = "0123456789";
	largol1 = l1.size();
	perm = factorial(largol1);
	permutar(l1,perm);

	cout<<"a) La cantidad de números pandigitales, para números entre 0-9, es: "<<perm<<endl;
	cout<<"b) La cantidad de números pandigitales que cumplen la propiedad es: "<<contador<<endl;
	cout<<"c) La suma de los números pandigitales que cumplen la propiedad es: ";for(auto x:sumapandigital){cout<<x;}cout<<endl;
	return 0;
}