#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <list>
#include <functional>   // std::multiplies
#include <numeric>      // std::partial_sum
#include <string>

using namespace std;

list<int> sumofvect(list<int> l1,list<int> l2)
{
	transform (l1.begin(), l1.end(), l2.begin(), l1.begin(),plus<int>());
	return l2;
}

list<int> prodVect(list<int> l1,list<int> l2)
{
	transform (l1.begin(), l1.end(), l2.begin(), l1.begin(),multiplies<int>());
	return l2;
}

vector<string> llenastring()
{
	vector<string> numeros;

	for(int i=0;i<1001;i++) 
	{

		numeros.push_back(to_string(i));
	}
	return numeros;
}

void imprime(vector<string> numb)
{
	for(int i=0; i<numb.size();i++)
	{	
		int f = stoi(numb[i]);
		cout<<"numb["<<i<<"] "<<f<<endl;
	}
}
/*
vector<int> factorial(vector<int> fact, vector<int> mult)
{
	vector<int> resultado;

	for (int i=0;i<1001;i++) 
	  	{
	  		fact[i]=i+1;
	  		partial_sum (fact,mult,resultado, multiplies<int>());
	  	}

	return resultado;
}
*/

int main () 
{
  	vector<string> numeros;
  	numeros = llenastring();	
  	imprime(numeros);

	return 0; 
}

/*
 for (int i=0;i<9;i++) 
  	{
  		numbers[i]=i+1;
  		partial_sum (numbers, numbers+9, factorials, multiplies<int>());
  	}
  for (int i=0; i<9; i++)
    cout << numbers[i] << "! is " << factorials[i] << '\n';
  return 0;
}
int main()
{
    
    cout<<"Los dígitos de 1000! son: "<<endl;

    for(it;it!=factorial.end();it++)
    {
        cout<<*it<<" ";
        sum+=*it;
        k++;
        cout<<"k: "<<k<<endl;
    }
    
    cout<<"\n\n1000! tiene "<<k<<" dígitos. "<<endl;

    cout<<"\nLa suma de sus digitos es: "<<sum<<"\n"<<endl;
    /*
    for(it;it!=factorial.end();it++)
    {
     //   cout<<"el valor de *it es:"<<*it<<endl;
        sum+=*it;
    }
*/





