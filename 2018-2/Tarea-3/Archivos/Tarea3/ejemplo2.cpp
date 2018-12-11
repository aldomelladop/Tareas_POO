#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream> 
#include <list>
#include <vector>
#include <math.h>


using namespace std;

vector<int> int2vector(int num);

vector<int> int2vector(int num) //Creamos una funcion para convertir de entero a vector
{
        int n = num;
        vector<int> v1;

        int r = 0, aux = 0;
        int d = 10;

        while(r!= n)  //Este while tiene como funcion, contar la cantidad de cifras que tiene n
        {
            r = n%d;
            d = d * 10;
            aux++;
        }
        aux--;

        int cif = aux;
        d = pow(10,cif);
        r = 0;

        while( cif >= 0)  //este while guarda cifra por cifra en el vector
        {
            int num = n / d;
            r = n % d;
            n = r;
            d /= 10;
            v1.push_back(num);
            cif--;
        }
        return v1;
}

int main()
{
	vector<int> vector1;        

	string a = "123456";
	long long int b = 0;

	b = stoi(a);
	vector1 = int2vector(b);
	for(auto x:vector1)
	{
		cout<<" "<<x;
	}
	return 0;
}