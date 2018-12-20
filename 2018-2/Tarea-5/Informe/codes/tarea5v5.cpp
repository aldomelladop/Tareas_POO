#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <algorithm>    // transform
#include <functional>   // plus
#include <ctype.h> // isnumber & isdigit

using namespace std;

typedef unsigned char uc;
typedef list<int> li;
typedef vector<int> vecint;
typedef vector<int>::iterator iterador;

int VectorToInt(vector<int> v); //función que convierte un vector a entero
vecint stringToVecint(string input); //funcion que convierte un string a un vector de enteros

class BigInteger {
	public:
		BigInteger();
		BigInteger(string input);

		bool esPar() const;
		bool esImpar() const;
		bool esChar() const;
		bool esShortInt()const;
		bool esLongInt()const;
		bool esLongLongInt()const;
		int signo() const;
		BigInteger abs() const;
		int cmp(BigInteger& q) const;

        //Destructor
       	~BigInteger();

       	///Funciones miembro
       	void setEntero(vecint a);
		vecint getEntero();

		void setSigno (int a);
		uc getSigno();

	private:
		int s;
		uc sign; // Toma valores -1 o 1
		vecint numero;
		vecint entero; // Parte entera del BigInteger
};

/*..............................................Constructores..........................................................*/

BigInteger::BigInteger(){}

BigInteger::BigInteger(string input)
{
	int k=0,j=0;
	string::iterator it1 = input.begin(); 

	int flag = 1;

	while(flag!=0)
	{
		k  = int(*it1-48);
		
		if(*it1=='-'&& j==0)
		{
			s = -1;
			flag=1;
		}
		else if((*it1=='0' && j==0) || (*it1=='0'&& j==1))
		{
			s=0;
			entero.push_back(0);
			flag=0;
		}
		else if(*it1=='.')
		{
			flag=0;
		}
		else 
		{
			if(s==-1)
			{
				entero.push_back(k);
				flag=1;
			}
			else
			{
				s = 1;
				entero.push_back(k);
				flag=1;	
			}
		}
		numero.push_back(k);
		it1++;
		j++;
	}

	if(s == -1)
	{
		sign = '-';
	}
	else if(s == 1)
	{
        sign = '0';
	}
	else if(s== 0)
	{
		sign = '0';
	}
}

void BigInteger::setEntero(vecint aux)
{
	entero = aux;
}

vecint BigInteger::getEntero()
{
	return entero;
}

void BigInteger::setSigno(int siggno)
{
	if(siggno ==-1)
	{
		sign = '-';
	}
	else if(siggno== 1)
	{
       sign = '+';
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

BigInteger BigInteger::abs()const
{
	string aux={""};

	for(auto x:entero)
	{
		cout<<x;
		aux.push_back(x);
	}

	BigInteger b(aux);

	return b;
}


bool BigInteger::esChar()const
{
	bool control=true;

	int n=VectorToInt(entero);

    if(n<(numeric_limits<char>::max()))
    {
	   	if(n>(numeric_limits<char>::min()))
	   	{
	       	return control=true;
	   	}
    }
    else
    	{
    		return control=false;
    	}
return control;
}


bool BigInteger::esShortInt()const
{
    bool control=true;

    int n=VectorToInt(entero);

    if(n<(numeric_limits<short int>::max()))
    {
        if(n>(numeric_limits<short int>::min()))
        {
            return control=true;
        }
    }
    else
        {
            return control=false;
        }
return control;
}

bool BigInteger::esLongInt()const
{
    bool control=true;

    int n=VectorToInt(entero);

    if(n<(numeric_limits<long int>::max()))
    {
        if(n>(numeric_limits<long int>::min()))
        {
            return control=true;
        }
    }
    else
        {
            return control=false;
        }
return control;
}


bool BigInteger::esLongLongInt()const
{
    bool control=true;

    int n=VectorToInt(entero);

    if(n<(numeric_limits<long long int>::max()))
    {
        if(n>(numeric_limits<long long int>::min()))
        {
            return control=true;
        }
    }
    else
        {
            return control=false;
        }
return control;
}

int BigInteger::cmp(BigInteger& q)const
{
    int comparador,signo1,signo2;
    vecint num1,num2;

    //Datos del objeto BigInteger con el cual se comparara
    
    num1 = entero;
    signo1 = s;

    //numero respecto del cual se hace la comparacion

    BigInteger aux(q);
    num2 = aux.getEntero();
    signo2 = aux.getSigno();



    if (signo1>signo2)
    {
        comparador = 1;   
    }
    else if(signo1<signo2)
    {
        comparador = -1;   
    }
    else
    {
        comparador = 0;   
    }   
    return comparador;
}



/*..............................................Destructor..........................................................*/

BigInteger::~BigInteger()
{
    sign=' ';
    numero.clear();
    entero.clear();
}

/*..............................................Funciones..........................................................*/

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

int VectorToInt(vector<int> v)
{
    reverse(v.begin(), v.end());
    int decimal = 1;
    int total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}
/*

vecint get_int(BigInteger b(string in))
{
    vecint aux;
    aux =  b.getEntero();

    return aux;
}

int get_signo(BigInteger b)
{
    int aux;
    
    aux =  b.getSigno();
    return aux;
}
*/

int main()
{
	vecint input,aux;
	string numero,numero1,numero2,q;

	cout<<"\nIngrese un número para crear el objeto BigInteger: ";
	//cin>>numero;
	numero = "-1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950.12";
	//numero = "0.0";
	numero1 = "0.0";
	numero2 = "1.1";

	cout<<endl;

	BigInteger bi(numero);

	cout<<"\n\tBigInteger("<<numero<<")"<<endl;

	aux = bi.getEntero();
	cout<<"\nProbando getEntero: ";
    for(auto x:aux){cout<<x;}

	cout<<"\nProbando getSigno: "<<bi.getSigno();

	cout<<"\nProbando abs(): ";	bi.abs();

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

	cout<<"\nProbando esChar: ";
	if(bi.esChar()==1)
	{
	cout<<"Sí cabe";
	}
	else
	{
        cout<<"El número no cabe";
	}

	cout<<"\nProbando esShortInt: ";
	if(bi.esShortInt()==1)
	{
	cout<<"Sí cabe";
	}
	else
	{
        cout<<"El número no cabe";
	}

	cout<<"\nProbando esLongInt: ";
	if(bi.esLongInt()==1)
	{
	cout<<"Sí cabe";
	}
	else
	{
        cout<<"El número no cabe";
	}

	cout<<"\nProbando esLongLongInt: ";
	if(bi.esLongLongInt()==1)
	{
	cout<<"Sí cabe";
	}
	else
	{
        cout<<"El número no cabe";
	}

	string aux1;
	cout<<endl<<"\nFavor ingrese el número que desea comparar con el objeto BigInteger";
	cin>>aux1;

	cout<<"\nProbando cmp(), comparando con:  ";
	
	cout<<"\n"<<endl;

	return 0;
}


