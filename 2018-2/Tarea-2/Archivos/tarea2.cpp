#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

///  1
///  1 1
///  2 1
///  1 2 1 1
///  1 1 1 2 2 1
///  3 1 2 2 1 1
///  1 3 1 1 2 2 2 1

using namespace std;

void despliegaSecuencia(vector<int>secuencia);

vector<int>countandSay(vector<int> look, int n)
{
    vector<int> aux;
    aux = look;
    look.clear();

    int counter=1;

    vector<int>::iterator it=aux.begin();

    for(it;it<aux.end();it++)
    {
        if(*(it)==*(it+1) && (it)!=aux.end()-1) //Busca coincidencias entre el valor y el valor posterior a este, haciendo la salvedad de que no se haga esta evaluacion
                //si es que se ha llegado al valor previo al termino del vector
        {
            counter++;
        }
        else
        {
            look.push_back(counter);
            look.push_back(*it);
            counter=1;
        }
    }
    return look;
}

void despliegaSecuencia(vector<int>secuencia)
{
    for(auto x:secuencia)
    {
        cout<<x;
    }
}

void cuentaNumeros(vector<int> secuencia)
{
    int c1=0,c2=0,c3=0,c4=0,largo=secuencia.size();
    for(auto x:secuencia)
    {
        if(x==1)
        {
            c1++;
        }
        else if(x==2)
        {
            c2++;
        }
        else if(x==3)
        {
            c3++;
        }
        else if(x==4)
        {
            c4++;
        }
    }

    cout<<"\nLa cantidad de números es: "<<largo<<endl;
    cout<<"La cantidad de números 1 es: "<<c1<<endl;
    cout<<"La cantidad de números 2 es: "<<c2<<endl;
    cout<<"La cantidad de números 3 es: "<<c3<<endl;
    cout<<"La cantidad de números 4 es: "<<c4<<endl;
}

int main()
{
	int n;
	vector<int> look,secuencia;

	cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea mostrar: ";
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cout<<"\n L["<<i<<"]: ";
        if(i==1)
        {
            look.push_back(1);
            despliegaSecuencia(look);
        }
        else if(i==2)
        {
            look.push_back(1);
            despliegaSecuencia(look);
        }
        else
        {
            look = countandSay(look,i);
            despliegaSecuencia(look);
        }
    }
    cout<<endl;
    cuentaNumeros(look);
	return 0;
}
