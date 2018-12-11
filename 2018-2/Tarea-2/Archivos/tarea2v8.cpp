#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void despliegaSecuencia(vector<int>secuencia);

vector<int>countandSay(vector<int> look, int n)
{
    vector<int> aux;
    aux = look;
    look.clear();

    //cout<<"\nAsegurandose que look no tiene nada: ";
    //despliegaSecuencia(look);
    //cout<<"\nlargo look: "<<look.size()<<endl;

    //cout<<"\nAsegurandose que aux contiene a look: ";
    //despliegaSecuencia(aux);
    //cout<<"\nlargo aux: "<<aux.size()<<endl;

    int counter=1;

    vector<int>::iterator it=aux.begin();
    //cout<<"\nImprimiendo"<<endl;
    for(it;it<aux.end();it++)
    {
     //   cout<<"*it: "<<*it<<endl;
        //cout<<"\nDentro del for"<<endl;
        if(*(it)==*(it+1) && (it)!=aux.end()-1) //Busca coincidencias entre el valor y el valor posterior a este, haciendo la salvedad de que no se haga esta evaluacion
                //si es que se ha llegado al valor previo al termino del vector
        {
          //  cout<<"\nDentro del if";
          //cout<<"\nCounter: "<<counter;
            counter++;
          //cout<<"\nCounter++: "<<counter;
        }
        //else if(it==aux.end()-1) //en caso contrario, h az una copia de los elementos almacenados en el vector, borra el vector actual
        else
        {
            //cout<<"\nDentro del else if"<<endl;
            //cout<<"Counter: "<<counter<<endl;
            look.push_back(counter);
            //cout<<"*it: "<<*it<<endl;
            look.push_back(*it);
            counter=1;
        }
        //despliegaSecuencia(look);
    }
     /*la finalidad de este vector era que se pudiera almacenar una copia de los valores que se empujaron al vector
    es decir, 21 en el caso de la tercera iteracion, o 1211 en el caso de la cuarta, sin embargo, no lo pude hacer. Se me ocurre que de alguna manera, la copia
    de este vector, debía ir fuera de esta función, fuera del for.*/
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
         //   cout<<"\nDentro del else"<<endl;
            look = countandSay(look,i);
            despliegaSecuencia(look);
        }
    }
    cout<<endl;
    cuentaNumeros(look);
    cout<<endl;
	return 0;
}