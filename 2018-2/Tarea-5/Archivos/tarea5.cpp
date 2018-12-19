 #include <iostream>
#include <string>
#include <list>
#include <stdexcept>
#include <algorithm>    // transform
#include <functional>   // plus

using namespace std;

class BigInteger {
	public:
		void setEntero(){return entero;}
		int setSigno(unsigned char);
		list<int> strtovect(string str);

	private:
		unsigned char signo; // Toma valores -1 o 1
		int sign = 1;
		string entero; // Parte entera del BigInteger
};

int BigInteger::setSigno(unsigned char s)
	{
		signo=s;
	}

void BigInteger::setEntero(strin g e)
{
	entero=e;
}

//Función que convierte de string a vector de enteros
list<int> BigInteger::strtovect(string str)
{
	list<int> list1;
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

void printvect(list<int> v)
{
	for(auto x:v)
	{
		cout<<x<<" ";
	}
}

list<int> sumofvect(list<int> l1,list<int> l2)
{
	transform (l1.begin(), l1.end(), l2.begin(), l1.begin(),plus<int>());
	return l2;
}


int main()
{
    bool sig;
    string a,b,d;
    BigInteger prueba;
    cout << "Ingrese un número"<< endl;
    cin>>a;

    prueba.setEntero(a);
    cout << "el numero es"<<endl;
    cout << " signo (1 positivo 0 negativo)" << prueba.sign()<<endl;
    cout << "" << prueba.enter();
    
    return 0;
   
}


