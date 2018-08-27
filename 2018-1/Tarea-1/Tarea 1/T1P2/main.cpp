#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>


using namespace std;

int main()
{
    vector<int> v1; //Se crea un vector de enteros
    int i,num=0,dig;
    for(i=100000000;i>=0;i--)
    {
         while(num!=0)
        {

           dig = num%10;
           v1.push_back(dig); //Se va rellenando el vector con los digitos
           num = num/10;
        }

        num=i;

    }
    reverse(v1.begin(),v1.end());//El vector se invierte, pues estaba al reves por las iteraciones del ciclo for


    int cont1=0,cont2=0;
    vector<int>::const_iterator iter=v1.begin();

       while (iter != v1.end())
        {
            if (*(iter) == 7&&
               *(iter+1) == 7&&
               *(iter+2) == 8&&
               *(iter+3) == 0)
                {
                     cont1++; //cont1: contador que lleva la cuenta de cuantas veces a ocurrido el numero
                }
                cont2++;//cont2:Este contador lleva la cuenta de las veces que ha ocurridd el ciclo


            if(cont1==7780){break;}//Se corta el ciclo en la n-sima aparicion de n
            ++iter;
        }
        cout<<cont2<<"<="<<cont1<<endl;

    return 0;
}
