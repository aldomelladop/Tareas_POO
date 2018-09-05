#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

void prob2(list<int>& l1,list<int>& l2)
{
	list<int>::iterator it1 = l1.begin();
	list<int>::iterator it2 = it1;
	l1.sort(); //listas ordenadas para poder usar merge
	l2.sort();
	l1.merge(l2); //agrega la lista  l2 a la lista l1. Ambvas listass deben estar ordenadas. La lista l2 queda vacía leugo de esto.
	/*hasta ahora, se ha cumplido la condición del problema que establece que la primera lista debe contener los elementos no repetidos de entre ambas listas*/
	it2++;

	while(it2!=it1)
	{
        if(*it2 == *it1)
            {
            l2.push_back(*it2); //se agregan los elementos repetidos a la lista l2
            it2  = l1.erase(it2); //se dejan, de la lista fusionada, sólo los elementos qe no coinciden
            }
            else
            it2++;it1++;
    }

}

int main()
{

list<int> l1,l2;
l1 = {-1,-2,4,6,8};
l2 = {4,0,2,6,7,-2,6,0,8};

prob2(l1,l2);
for(int n:l1)
	{
		cout<<n<<" ";
	}
cout<<endl;

for(int n:l2)
	{
		cout<<n<<" ";
	}
cout<<endl;

	return 0;
}
