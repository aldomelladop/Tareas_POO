#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void slas(vector<int> lass, int z)
{
    int counter=1;
    vector <int> ssal,ds;
    ssal = lass;
    lass.clear();
    ds.clear();

    vector <int>::iterator it=ssal.begin();

    //cout<<"contador "<<counter<<endl;

    for(it;it<=ssal.end();it++)
    {
        if(*(it)==*(it+1) && (it+1)!=ssal.end()) //Evita que en la iteración siguiente, se produzca que compare el ultimo elemento con el siguiente luego del ultimo
        {
            cout<<"\nentra al if"<<endl;
            cout<<"El valor del counter es: "<<counter<<endl;
            counter++;
        }
        else if(it==ssal.begin())
        {
            cout<<"Entra al else if: "<<endl;
            lass.push_back(*it);
        }
        else
        {
            cout<<"Entra al else"<<endl;
            cout<<"El valor del iterador es "<<*it<<endl;
            cout<<"El valor del contador es: "<<counter<<endl;
            lass.push_back(counter);
            lass.push_back(*it);
        }
    }
    ds = lass;
    counter = 1; //Inicializamos en 1 el contador, a contar de la segunda ocurrencia será 2.

    cout<<"\nL"<<z<<" ";
    for(auto x:ds){cout<<x;}
}

int main()
{
    int n,escape=0;
    vector <int> lass; //lass = look and say sequence

    do
    {
    cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea mostrar: ";
    cin>>n;

    cout<<"\nEs la secuencia correspondiente a la línea: \n"<<endl;
    for(int z=1;z<=n;z++)
    {
        if(n==1)
        {
            //cout<<"entrando al if"<<endl;
            cout<<"L1: ";
            lass.push_back(1);
            for(auto x:lass){cout<<x<<endl;}
            lass.clear();
        }
        else if(n==2)
        {
            //cout<<"entrando al else if"<<endl;
            lass.clear();
            for(int i=1;i<=2;i++)
            {
                lass.push_back(1);
            }
            cout<<"L2: ";
            for(auto x:lass){cout<<x;}
            cout<<"\n";
        }
        else
        {
            //cout<<"\nL"<<j<<" ";
            //cout<<"entrando al else"<<endl;
            slas(lass,n);

        }
    }
    cout<<"\ningrese cualquier valor si desea repetir el calculo, o 0 si es que desea salir: ";
    cin>>escape;
    }
    while(escape!=0);
    return 0;
}

