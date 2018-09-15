#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

int factorial(int len)
{
	int factorial=1;

	for(int i=1;i<=len;i++)
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
		cout<<"\n";
		if((j%10)!=0)
		{cout<<j;}
	}
	salida.close();
}

void revisar(int len)
{

    list<int> c1,c2;
    int temp,count;

    ifstream entrada("salida.txt");
    ofstream salida("rev_salida.txt");

    cout<<"\n";

    while(entrada >> temp)
	{
		cout<<"temp: "<<temp<<endl;
		c1.push_back(temp);
		count=c1.size();

			if(count==len)
			{
				for(auto x:c1)
				{
	                salida<<x;
	            }
	          salida<<"\n";
			}
	}
	entrada.close();
	salida.close();
}

 int main()
{
	long int len,perm=0;
	list<int>l1;
//	l1 = {0,1,2,3,4,5,6,7,8,9};
	l1 = {0,1,2,3};

	len = l1.size();

	perm = factorial(len);
	cout<<"Resultado Factorial "<<perm;

	//for(auto x:l1){cout<<x;}
	permutar(l1,perm);
	revisar(len);

	return 0;
}
