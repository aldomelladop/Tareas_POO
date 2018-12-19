#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <algorithm>    // transform
#include <functional>   // plus
#include <ctype.h> // isnumber & isdigit

//#include <stdexcept>

using namespace std;

typedef unsigned char uc;
typedef list<int> li;
typedef vector<int> vecint;
typedef vector<int>::iterator iterador;

class BigInteger {
	public:
		BigInteger();
		BigInteger(string input);

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

///Constructores
BigInteger::BigInteger(){}

BigInteger::BigInteger(string input)
{
	int largo = input.size();

	int k=0,j=0;
	string::iterator it1 = input.begin(); 

	int flag = 1;

	while(flag!=0)
	{
		k  = int(*it1-48);
		
		if(*it1=='-'&& j==0)
		{
//			cout<<"\nEntro al if"<<endl;
			signo = -1;
			flag=1;
		}
		else if((*it1=='0' && j==0) || (*it1=='0'&& j==1))
		{
//			cout<<"\nEntro al else if"<<endl;
			signo=0;
			entero.push_back(0);
			flag=0;
		}
		else if(*it1=='.')
		{
//			cout<<"flag cambiada"<<endl;
			flag=0;
		}
		else
		{
//			cout<<"\nEntro al else"<<endl;
			signo = 1;
			entero.push_back(k);
			flag=1;
		}
		numero.push_back(k);
		it1++;
		j++;
	}

	if(signo = -1)
	{
		sign = '-';
	}
	else if(signo = 1)
	{
        sign = ' ';
	}
	else if(signo= 0)
	{
		sign = '0';
	}
	else
	{
		cout<<"Error";
	}
}

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
	else if(siggno = 1)
	{
        sign = ' ';
	}
	else if(siggno= 0)
	{
		sign = '0';
	}
	else
	{
		cout<<"Error";
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
	string numero,numero1,numero2;

	cout<<"\nIngrese un número para crear el objeto BigInteger: ";
	//cin>>numero;
	numero = "-1.1";
	numero1 = "0.0";
	numero2 = "1.1";

	cout<<endl;

	BigInteger bi(numero);
	BigInteger bi1(numero1);
	BigInteger bi2(numero2);

	cout<<"\n\tBigInteger("<<numero<<")"<<endl;

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

	cout<<endl;

	///............................................................................

	cout<<"\n\tBigInteger("<<numero1<<")"<<endl;
	
	aux = bi1.getEntero();
	cout<<"\nProbando getEntero: ";
    for(auto x:aux){cout<<x;}

	cout<<"\nProbando getSigno: "<<bi1.getSigno();

	cout<<"\nProbando esPar: ";
	if(bi1.esPar()==1)
	{
	cout<<"Sí, es par";
	}
	else
	{
        cout<<"El número no es par";
	}

    cout<<"\nProbando esImpar: ";
	if(bi1.esImpar()==1)
	{
	cout<<"Sí, es Impar";
	}
	else
	{
        cout<<"El número no es Impar";
	}

	cout<<endl;

	///............................................................................

	cout<<"\n\tBigInteger("<<numero2<<")"<<endl;

	aux = bi2.getEntero();
	cout<<"\nProbando getEntero: ";
    for(auto x:aux){cout<<x;}

	cout<<"\nProbando getSigno: "<<bi2.getSigno();

	cout<<"\nProbando esPar: ";
	if(bi2.esPar()==1)
	{
	cout<<"Sí, es par";
	}
	else
	{
        cout<<"El número no es par";
	}

    cout<<"\nProbando esImpar: ";
	if(bi2.esImpar()==1)
	{
	cout<<"Sí, es Impar";
	}
	else
	{
        cout<<"El número no es Impar";
	}

	cout<<endl;
	cout<<endl;


	return 0;
}


