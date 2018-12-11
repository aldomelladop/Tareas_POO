#include <iostream>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

vector<int> vect;                                              //declara vector entero llamado vect

void factorial(int n)
{
    vect.push_back(1);                                         //para agregar datos al vector
    int acarreo = 0,temp;

    for(int i = 2; i <= n; i++)                                //comienzo con el calculo del factorial
    {
        for(int j = 0; j < vect.size(); j++)                   //vect.size: el tamaño actual del vector
        {
            temp= vect[j]*i;                             //1era iteracion 1*2, 2*3
            vect[j] = (temp + acarreo)%10 ;                     //(2 + 0)%10 = 2, (6+0)%10
            cout<<"\nvect["<<j<<"]: "<<vect[j];
            acarreo = (temp + acarreo)/10;                      //acarreo = 0, acarreo = 0
        }
        while(acarreo != 0)
        {
            vect.push_back(acarreo%10);                        //aumento del vector, cuando el resto es != de cero
            acarreo = acarreo/10;
        }
    }

    for(int i = vect.size()-1; i>= 0; i--)                     //nos entrega el valor del factorial calculado
        cout<<vect[i];
}

int main()
{
    int num;
    cout<<"Ingrese el numero : ";
    cin>>num;                                                  //capturar el numero desde la pantalla
    cout<<num<<"! es ";
    factorial(num);

    int suma = accumulate(vect.begin(), vect.end(), 0);

    cout<<"\nY la suma de sus digitos es: "<<suma;

    return 0;
}
