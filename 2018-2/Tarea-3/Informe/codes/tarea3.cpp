#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

void propiedad(string l2);// se llama a la funcion debido a que como se concibio la solucion, propiedad depende de permutar y este depende de factorial.

int cdv2=0,cdv3=0,cdv5=0,cdv7=0,cdv11=0,cdv13=0,cdv17=0,sumapandigital=0;

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

	if(dv2%2==0)
	{
		cdv2++;
		sumapandigital = sumapandigital +dv2;
	}
	else if(dv3%3==0)
	{
		cdv3++;
		sumapandigital = sumapandigital +dv3;
	}
	else if(dv5%5==0)
	{
		cdv5++;
		sumapandigital = sumapandigital +dv5;
	}
	else if(dv7%7==0)
	{
		cdv7++;
		sumapandigital = sumapandigital +dv7;
	}
	else if(dv11%11==0)
	{
		cdv11++;
		sumapandigital = sumapandigital +dv11;
	}
	else if(dv13%13==0)
	{
		cdv13++;
		sumapandigital = sumapandigital +dv13;
	}
	else if(dv17%17==0)
	{
		cdv17++;
		sumapandigital = sumapandigital +dv17;
	}
}

 int main()
{
	string l1;
	int largol1,perm=0,suma=0;


	l1 = "0123456789";
	largol1 = l1.size();
	perm = factorial(largol1);
	permutar(l1,perm);

	suma =  cdv2+cdv3+cdv5+cdv7+cdv11+cdv13+cdv17;
	cout<<endl;

	cout<<"a) La cantidad de números pandigitales, para números entre 0-9, es: "<<perm<<endl;
	cout<<"b) La cantidad de números pandigitales que cumplen la propiedad es: "<<suma<<endl;
	cout<<"c) La suma de los números pandigitales que cumplen la propiedad es: "<<sumapandigital<<endl;
	cout<<endl;
	return 0;
}