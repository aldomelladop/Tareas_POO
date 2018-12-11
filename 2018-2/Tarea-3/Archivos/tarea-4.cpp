#include<iostream>
#include<fstream>
#include<list>
#include<vector>

vector<float> leerelementos(vector<int>v1)
{
	ifstream entrada("eventos.txt");

	while(entrada>>temp)
	{
		v1.push_back(temp);
	}
}

void imprimevector(vector<float>v2)
{
	for(auto x:v2)
	{
		cout<<x;
	}
}

int main()
{
	vector<int> v1;
	leerelementos(v1);
	imprimevector(v1);
	return 0;
}