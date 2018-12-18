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
				//cout<<"k "<<k<<endl;

				if(it1==input.begin() && k!=0)
				{
					sign = *it1;
					signo = *it1;
				}
				else
				{
					sign = ' ';
					signo = 1;
					entero.push_back(k);
				}
				numero.push_back(k);
			}
			if(signo = -1)
			{
				sign = '-';
			}
			else
			{
		        sign = ' ';
			}
		}
		void setEntero(vecint a);
		vecint getEntero();

		void setSigno (int a);
		uc getSigno();

		bool esPar() const;
		bool esImpar() const;
		//int signo() const;
		//BigInteger abs() const
		//int cmp(BigInteger& q) const;

		//li strToList(string str);

       	//Destructor
       	~BigInteger();
	private:
		int signo;
		uc sign; // Toma valores -1 o 1
		vecint numero;
		vecint entero; // Parte entera del BigInteger
};


bool BigInteger::esPar() const
{
	bool flag;
	vecint aux = entero;

	iterador it=aux.begin();

	if(*(aux.end()-1)==0 || *(aux.end()-1)==2 || *(aux.end()-1)==4 || *(aux.end()-1)==6 || *(aux.end()-1)==8)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}
	return flag;
}

bool BigInteger::esImpar() const
{
	bool flag;

	if(*(numero.end()-1)==1 || *(numero.end()-1)==3 || *(numero.end()-1)==5 || *(numero.end()-1)==7 || *(numero.end()-1)==9)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	return flag;
}

void BigInteger::setSigno(int siggno)
{
	if(siggno = -1)
	{
		sign = '-';
	}
	else
	{
        sign = ' ';
	}
}

uc BigInteger::getSigno()
{
	return sign;
}

void BigInteger::setEntero(vecint aux)
{
	entero = aux;
}

vecint BigInteger::getEntero()
{
	return entero;
}

BigInteger::~BigInteger()
{
    sign=' ';
    numero.clear();
    entero.clear();
}

/*
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
*/

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
	vecint input, aux;
	string numero;

	cout<<"\nIngrese un número para crear el objeto BigInteger: ";
	cin>>numero;

	BigInteger bi(numero);

	cout<<"BigInteger("<<numero<<")"<<endl;

	aux = bi.getEntero();
	cout<<"\nProbando getEntero: ";
    for(auto x:aux){cout<<x;}

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


