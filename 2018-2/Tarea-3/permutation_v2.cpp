#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

int factorial(int largol1)
{
	int factorial=1;

	for(int i=1;i<=largol1;i++)
	{

		factorial=factorial*i;
	}
	return factorial;
}

void permutar(list<int>l1,int factorial)
{
	int j=0;
	list<int>l2;
	l2 = l1;
	//ofstream salida("resultado.txt",ofstream::out);
    ofstream salida("salida.txt");

	while(j<factorial)
	{
        list<int>::iterator it=l2.begin();

        for(auto x:l2)
			{
                salida<<x;
            }
        salida<<"\n";

        next_permutation(l2.begin(),l2.end());
		j++;
		//cout<<"\n";
		if((j%10)==0)
		{cout<<"\n"<<j;}
	}
	salida.close();
}

void revisar(int largol1)
{

    list<int> c1,c2;
    
    int temp;
    int count=0,largoc1=0;

    ifstream entrada("salida.txt");
    ofstream salida("rev_salida.txt");

    cout<<"\n";

    while(entrada >> temp)
	{	
		int a=0;
		
		cout<<"temp: "<<temp<<endl;

		c1.push_back(temp);
	}
	
	list<int>::iterator it=c1.begin();

	for(it;it!=c1.begin();it++)
	{
		list<int> a;
		a.push_back(*it);
		
		largoc1 =a.size();

		if(largoc1=largol1)
		{
		salida<<*it;
		}
	}
	/*for(auto x:c1)
	{	
		largoc1 = c1.size();
		if(largoc1==largol1)
		{salida<<x;}

	cout<<"C"<<count<<": "<<x<<endl;count++;
	}
	*/

	entrada.close();
	salida.close();
}

 int main()
{
	long int largol1,perm=0;
	list<int>l1;
//	l1 = {0,1,2,3,4,5,6,7,8,9};
	l1 = {0,1,2,3};

	largol1 = l1.size();

	perm = factorial(largol1);
	cout<<"Resultado Factorial "<<perm;
	permutar(l1,perm);
	revisar(largol1);

	return 0;
}
