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
			signo = -1;
			flag=1;
		}
		else if((*it1=='0' && j==0) || (*it1=='0'&& j==1))
		{
			signo=0;
			entero.push_back(0);
			flag=0;
		}
		else if(*it1=='.')
		{
			flag=0;
		}
		else 
		{
			if(signo==-1)
			{
				entero.push_back(k);
				flag=1;
			}
			else
			{
				signo = 1;
				entero.push_back(k);
				flag=1;	
			}
		}
		numero.push_back(k);
		it1++;
		j++;
	}

	if(signo == -1)
	{
		sign = '-';
	}
	else if(signo == 1)
	{
        sign = '0';
	}
	else if(signo== 0)
	{
		sign = '0';
	}
}

bool BigInteger::esPar() const
{
	bool flag;

	if(*(entero.end()-1)==0 || *(entero.end()-1)==2 || *(entero.end()-1)==4 || *(entero.end()-1)==6 || *(entero.end()-1)==8)
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

	if(*(entero.end()-1)==1 || *(entero.end()-1)==3 || *(entero.end()-1)==5 || *(entero.end()-1)==7 || *(entero.end()-1)==9)
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
	if(siggno ==-1)
	{
		sign = '-';
	}
	else if(siggno== 1)
	{
       sign = '\0';
	}
	else if(siggno==0)
	{
		sign = '\0';
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
	numero = "-123.12";
	numero1 = "0.0";
	numero2 = "1.1";

	cout<<endl;

	BigInteger bi(numero);

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
	return 0;
}