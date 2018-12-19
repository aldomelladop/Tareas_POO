#include <iostream>
#include <string>
#include <vector>
//#include <list>
#include <algorithm>    // std::transform
#include <functional> //plus

using namespace std;

void sumofvect(vector<int> v1,vector<int> v2)
{
	cout<<"\nEntré a sumofvect"<<endl;
	vector<int> foo,bar;
	foo = v1;
	bar = v2;

	cout<<"Los elementos de v1 (foo) son: ";
	for(auto x:foo)
	{
		cout<<x<<" ";

	}

	cout<<"\nLos elementos de v2(bar) son: ";
	for(auto x:bar)
	{
		cout<<x<<" ";
	}
	transform (foo.begin(), foo.end(), bar.begin(), foo.begin(),plus<int>());


	cout<<"\nLa suma de los elementos de los vectores v1, v2, es: ";
	for(auto x:foo){cout<<x;}
	cout<<endl;
}

int main()
{
	int j=0,k=0,l=0;
	vector<int> vect1,vect2;
	string r,s;

	cout<<"ingrese un valor de string: ";
	cin>> s;

	cout<<"\nYou entered: "<<s<<endl;

	string::iterator it1 = s.begin();

	for(it1;it1!=s.end();it1++)
	{
		j++;
		k  = int(*it1-48);
		vect1.push_back(k);
	}

	cout<<"\n\nLa cantidad de dígitos del número ingresado es: "<<j<<endl;

	cout<<"\nEl vector v1 transformado es: ";
	for(auto x:vect1)
	{
		cout<<x<<" ";
	}

	cout<<"\n\nIngrese otro número: ";
	cin>>r;

	cout<<"\nYou entered: "<<s<<endl;

	string::iterator it2 = r.begin();

	for(it2;it2!=r.end();it2++)
	{
		l++;
		k  = int(*it2-48);
		vect2.push_back(k);
	}
	cout<<"\nLa cantidad de dígitos del número ingresado es: "<<l<<endl;

	cout<<"\nEl vector v2 transformado es: ";
	for(auto x:vect2)
	{
		cout<<x<<" ";
	}
	cout<<endl;

	int a, b;
	vector<int>::iterator it3 = vect1.begin();
	vector<int>::iterator it4 = vect2.begin();
	a = vect1.size();
	b = vect2.size();

	cout<<"\nTamaño vector 1: "<<a<<endl;
	cout<<"\nTamaño vector 2: "<<b<<endl;

 //Si el string f1 es menor, se agregan ceros a la derecha  tantas veces como diferencia de largo tengan
    if(a<b)
    {
    	cout<<"\nCaso a<b"<<endl;
 		long int dife = b-a;
 		reverse(vect1.begin(),vect1.end());
        for(long int c=0;c!=dife;c++)
		{
        	vect1.push_back(0);
		}
		reverse(vect1.begin(),vect1.end());
		sumofvect(vect1,vect2);
	}

//Si el string f2 es menor, se agregan ceros a la derecha  tantas veces como diferencia de largo tengan
	else if(a>b)
    {
    	cout<<"\nCaso a>b"<<endl;
    	long int dife = a-b;
    	reverse(vect2.begin(),vect2.end());
        for(long int c=0;c!=dife;c++)
    	{
        	vect2.push_back(0);
		}
		reverse(vect2.begin(),vect2.end());
		sumofvect(vect1,vect2);
    }
	else if(a==b)
	{
		cout<<"\nCaso a=b"<<endl;
		sumofvect(vect1,vect2);
	}


	return 0;
}
