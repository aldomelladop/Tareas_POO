#include <iostream>
#include <utility> 
#include <string>
#include <vector>
#include <list>
#include <algorithm>    // transform
#include <functional>   // plus
//#include <stdexcept>

using namespace std;

typedef unsigned char uc;
typedef list<int> li;
typedef pair<string,char> psc;
typedef vector<int> vecint;
typedef vector<int>::iterator iterador;
class BigInteger {
	public:
		BigInteger(string input)
		{
			int k=0;
			string::iterator it1 = input.begin();

			for(it1;it1!=input.end();it1++)
			{
				k  = int(*it1-48);
				numero.push_back(k);
			}
		}

		void setEntero(string a);
		void setSigno (string b);
		void set();
		int get();
		string getEntero();
		uc getSigno();
		//int signo() const;
		//BigInteger abs() const
		//int cmp(BigInteger& q) const;
		bool esPar() const;
		bool esImpar() const;
		li strToList(string str);

	private:
		uc signo; // Toma valores -1 o 1
		int sign = 1;
		vecint numero; // Parte entera del BigInteger
};

bool BigInteger::esPar() const
{
	iterador it=numero.begin();

	if((*(numero.end()-1)%2)!=0)
	{
		flag = false;
	}
	else
	{
		flag = true;
	}

	return flag;
}

bool BigInteger::esImpar() const
{
	bool flag;

	if((stoi(numero)%2)!=0)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	return flag;
}

void BigInteger::setSigno(string s)
{
	int aux = stoi(s);

	if(aux>=0)
	{
		signo = '1';
	}
	else
	{
		signo = '-';
	}
}

void BigInteger::setEntero(string input)
{
	numero=input;
}

string BigInteger::getEntero()
{
	return numero;
}

uc BigInteger::getSigno()
{
	return signo;
}

void BigInteger::set(int n1)
{
	aux = n1;
}

uc BigInteger::get()
{

}
//Función que convierte de string a lista de enteros
li BigInteger::strToList(string str)
{
	li list1;
	int j=0,k=0;
	string s = str;
	string::iterator it1 = s.begin();

	for(it1;it1!=s.end();it1++)
	{
		j++;
		k  = int(*it1-48);

		if(*it1=='-')
		{
			list1.push_back(0);
			//sign.set(-1);
		}

		else
		{
			list1.push_back(k);
			//sign.set(1);
		}
	}
	return list1;
}

void printList(li v)
{
	for(auto x:v)
	{
		cout<<x<<" ";
	}
}

 li sumofList(li l1,li l2)
{
  li suma = l2;
  transform (l1.begin(), l1.end(), suma.begin(), suma.begin(),plus<int>());
  return suma;
}

int main()
{
	li input;
	string numero;

	cout<<"\nIngrese un número para crear el objeto BigInteger: ";
	cin>>numero;

	BigInteger bi(numero);
	cout<<"BigInteger("<<numero<<")"<<endl;
	cout<<"\nProbando setEntero ";
	bi.setEntero(numero);
	cout<<"\nProbando set signo ";
	bi.setSigno(numero);
	cout<<"\nProbando getEntero: "<<bi.getEntero();
	cout<<"\nProbando getSigno: "<<bi.getSigno();

	cout<<"\nProbando esPar: ";
	if(bi.esPar()==1)
	{
	cout<<"Sí, es par";
	}
	else
	{
        cout<<"El número no es par";
	}

    cout<<"\nProbando esImpar: ";
	if(bi.esImpar()==1)
	{
	cout<<"Sí, es Impar";
	}
	else
	{
        cout<<"El número no es Impar";
	}
    return 0;
}


