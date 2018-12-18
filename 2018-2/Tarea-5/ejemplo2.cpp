#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<int> aux;
	string numero;
	cout<<"Ingrese un número: ";cin>>numero;

	for(auto x:numero)
	{
		aux.push_back(int(x));
	}

	for(auto x:aux)
	{
		cout<<x;
	}

	return 0;
}