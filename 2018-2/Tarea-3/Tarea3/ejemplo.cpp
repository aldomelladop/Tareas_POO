#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;


 int main()
{	
	int a = 0;
	char temp;
	list<int> list_int;
	list<int>::iterator it_int = list_int.begin();

	list<char>list;
	
	
	ifstream entrada("ejemplo.txt");

	while(entrada >> temp)
	{
		list.push_back(temp);
	}
	for(auto x:list)
	{
		cout<<"x: "<<x<<endl;
	list_int.push_back(x);
	}

	for(it_int;it_int!=list_int.end();it_int++)
	{
		a = a + *it_int;
	}
	cout<<"El valor de la suma de los elementos del vector es: "<<a<<endl;


	
	

	entrada.close();
	

	return 0;
}
