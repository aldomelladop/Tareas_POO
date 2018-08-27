#include<iostream>
#include<math.h>
#include<iomanip>
#include <vector>
#include <map>

using namespace std;

vector<int> vec,opp; int tam;

vector<int> cambiodesigno(vector<int> vec)
{
    vector<int>::iterator it=vec.begin();
    vector<int>::iterator itp=opp.begin();
    
    for(it;it<vec.end();it++)
    {
        //*it = (*it)*(-1);
        opp.push_back((*it)*(-1));
    }
    
    return opp;
}

int calcularSuma(vector<int> vecto)
{
    vector<int>::iterator it1=vecto.begin();
    
    int Suma=0;
    for(it1; it1<vecto.end(); it1++)
    {
        Suma = Suma + (*it1);
    }
    return Suma;
}

void imprimevector(vector<int> vect)
{
    vector<int>::iterator it2=vect.begin();
    cout<<"[";
    for(it2; it2<vect.end(); it2++)
    {
        cout<< *it2 <<" ";
        if(it2==vect.end()-1)
        {
        	cout<<"]";
        }
    }
}

void pedirDatos()
{
    int n;
    cout<< "Digite el número de elementos del vector: ";
    cin>>tam;
    
    for(int i=0;i<tam;i++)
    {
        cout<<i+1<<". Digite el número: ";
        cin>>n;
        vec.push_back(n);
        //it++;
    }
}

int main()
{
    pedirDatos();
    imprimevector(vec);
//    imprimevector(cambiodesigno(vec));

     cout<<"\nLa suma de los datos del vector es: "<<calcularSuma(vec)<<endl;
     cout<<"\nLos elementos del vector con signo cambiado son: ";
     imprimevector(cambiodesigno(vec));
    
    
    return 0;
}