#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> auxiliar;

int sum()
{
  int sum = accumulate(auxiliar.begin(), auxiliar.end(), 0);
  return sum;
}

void factorial(int num)
{
  auxiliar.push_back(1); //0!
  int c = 0;

   for(int i=1;i<=num;i++)
   {
     for(int j=0;j<auxiliar.size();j++)
        {
           int temp = auxiliar[j]*i; // x contiene el producto dígito a dígito
           auxiliar[j]=(temp+c)%10; //Contiene el dígito almacenado en la posición j-ésima
           c = (temp+c)/10; //Contiene el valor del acarreo que será almacenado más tarde en los índices
        }
         while(c>0) //el ciclo while almacena el valor de acarreo en el vector
         {
           auxiliar.push_back(c%10);
           c = c/10;
         }
    }

    cout<<"El factorial de "<<num<<" es: ";

    reverse(auxiliar.begin(),auxiliar.end());
    vector<int>::iterator it=auxiliar.begin();

    for(it;it!=auxiliar.end();it++)
    {
      cout<<*it;
    }

    int suma = sum();
    cout<<"\n\nLa suma de sus dígitos es: "<<suma<<endl;
}

int main()
{
    int n;
    cout<<"\nIngrese el número del cual desea calcular el factorial: ";
    cin>>n;

    while(n<0)
    {
      cout<<"El factorial no está definido para números negativos, intente nuevamente: ";
      cin>>n;
    }

    factorial(n);

    return 0;
}
