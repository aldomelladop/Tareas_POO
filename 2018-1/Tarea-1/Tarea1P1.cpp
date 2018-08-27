//Problema 1 Tarea 1
#include <list>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

//  cout << "askhdbahksd" << endl;
	int length1,length2,length3,m,aux=0,C=0,i=0,fibo;
    list<int> suma,L1,L2;
    list<int>:: iterator it1,it2;

    L1.push_back(1);
    L2.push_back(1);

	it1 = L1.begin();
	it2 = L2.begin();
	length1 = L1.size();
	length2 = L2.size();

	while(length2<=999)
	{
		for(it2=L2.begin(); it2!=L2.end();it2++)
		{
            aux = *it1 + *it2 + C;
        	cout<<"--"<<aux<<"--"<<endl;
			m = aux%10;

			if (aux<10)
			{
				suma.push_back(aux);
				cout<<"--"<<aux<<"--"<<endl;
				C = 0;
			}
			else
            {
                suma.push_back(m);
				C = 1;
			}
            it1++;
        }
		L1.clear();
		L1=L2;
		it1 = L1.begin();
		L2.clear();
		L2 = suma;
		suma.clear();

		length1 = L1.size();
		length2 = L2.size();

		cout << length2<<endl;
		    length3 =  length2- length1;
        if (length1!= length2)
        {
            for (i=0;i<length3;i++)
            {
                L1.push_back(0);
            }
        }

    }

if (length2>= 1000)

{
	for (int x:L2)
	{
	fibo = x + fibo;
	cout << fibo<<endl;
	cout << *it1;
	}
}
return 0;
}
//int len1, i=0;
//list <int> lista;
//
//len1 = 0;
//
//while(len1<=2000)
//{   cout<<len1<<endl;
//    for(i;i<50;i++)
//    {
//        lista.push_back(i);
//    }
//
//    len1 = lista.size();
//}
//
//for(int x:lista)
//{
//    cout << x << endl;
//}
//
//return 0;
