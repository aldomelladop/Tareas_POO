//ejemplo1.cpp

#include <iostream>     // cout
#include <algorithm>    // transform
#include <vector>       // vector
#include <functional>   // plus
#include <list>

using namespace std;

list<int> strtovect(string str)
{
    int signo = 1; //1 es positivo, -1 es negativo
	list<int> l1;
	int j=0,k=0;
	string s = str;
	string::iterator it1 = s.begin();

	for(it1;it1!=s.end();it1++)
	{
		j++;
		k  = int(*it1-48);
		
		if(k==-3)
		{

        }
        else
        {
		l1.push_back(k);
		}
	}

	//cout<<"\n\nLa cantidad de dígitos del número ingresado es: "<<j<<endl;

	/*cout<<"\nEl vector v1 transformado es: ";
	for(auto x:vect1)
	{
		cout<<x<<" ";
	}
	*/
	return l1;
}

int main () {

list<int> lis1;
string str;

cout<<"Ingrese un valor: ";cin>>str;
lis1 = strtovect(str);


for(auto x:lis1)
{
	cout<<x<<" ";
}

return 0;
}

