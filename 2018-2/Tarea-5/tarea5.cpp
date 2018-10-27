#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

class BigInteger
{
public:
		bool signo()
			{return sign;}
		string numero()
			{return number;}
		void setsigno(bool);
		void setstring(string);
private:
		bool sign;
		int num; 
		string str1, number;
		vector<int> vect;
};

/*
void BigInteger::setsigno(bool s)
{
	sign = s;
}
*/

vector<int> autotovector(auto autox)
{
	vector<int> integer;
	string number;
	int numbint,j=0;

	number = to_string(autox);
	
	string::iterator it=number.begin();

	for(it;it!=number.end();it++)
	{
		int (numbint) = int(*it-48); //Usado para convertir el caracter desde ASCII a Decimal
		integer.push_back(numbint);
		j++;
	}
	cout<<"Cantidad de elementos: "<<j<<endl;
	return integer;
}

/*
vector<int> BigInteger::s_to_int(string number)
{
	num = stoi(numb);
 	vect = num2vec(num);
 	return vect;
}
*/


vector<int> num2vec(int value)
{
   vector<int> num;
   const int base = 10;
   int digit = value % base;

   if ( value /= base )
   {
   	 num2vec(value);
   }

   num.push_back(digit); /* Si va anotada acá, es similar a que se aplicara un reverse */
   
   return num;
}

int main()
{
	vector<int> vec;
	str c= 5819819819811313314;
	vec = autotovector(c);
/*	BigInteger bi;
	bi.setsigno(0);
	bi.autotostring(c);
	vec = bi.num2vec(c);
	cout<<bi.signo()<<" "<<bi.numero()<<endl;
*/
	cout<<"Mostrar elementos vector:";
	for(auto x:vec){cout<<x<<" ";}
	return 0;
}	