#include <iostream>

using namespace std;

int main()
{
	int n,j;
	int s=0;

	cout<<"Ingrese un valor de n "<<endl;
	cin>>n;
/*
	while(n>0)
	{
		s = s + n%10;
		n = n/10;
	}

	cout<< "Suma de dígitos >> "<<s<<endl;
*/	
	s  = n/10;
	j  = n%10;

	cout<<"n/10 "<<s<<endl;
	cout<<"n%10 "<<j<<endl;

	return 0;
}