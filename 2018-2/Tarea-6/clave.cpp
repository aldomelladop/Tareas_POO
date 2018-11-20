#include <iostream>
#include <stdexcept>    // Domain_error
#include <algorithm>    // std::sort
#include <string>       // std::string
#include <vector>       // std::vector
#include <list>
#include <map>

using namespace std;

//void encripta(const string& p)
void encripta(const string& p)
{   

	map<char,char> codificador;

	string  clave;
	string abecedario = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string  clave1 = p;
	string salida;

	string::iterator iter = clave1.begin();
	for(iter;iter!=clave1.end();iter++)
	{
	    clave.push_back(toupper(*iter));
	}
 
 	cout<<"\nImprimiendo palabra: "<<clave<<endl;

    int largo = clave.size();
//    string::iterator iter2=palabra.begin();
    
    for(int i=0;i<largo;i++)
      {
        codificador.insert(make_pair(abecedario[i],clave[i]));
      }
    for(auto x:codificador)
    {
        cout << "(" << x.first << ","<< x.second << ")"<<endl;
    }

    string::iterator iter1 = clave.begin();
    map<char,char>::iterator iter2 = codificador.begin();

	for(iter1;iter1!=clave.end();iter1++)
		{
			if(codificador.find(*iter1)==codificador.end())
			{
				salida.push_back(*iter1);
			}
			else
			{
				salida.push_back(codificador.find(*iter1)->second);
			}
		}
	
	cout<<"\nLa clave codificadora fue: "<<clave<<"\nLa palabra codificada  fue: "<<salida<<endl;
	salida.clear();
}	

int main()
{	

	//// Lo que se tiene hasta ahora, es que se ingresará la clave a codificar, tal que con ella se hará la codificación de las palabras que se ingresan desde el texto
	string clave;
	cout<<"Ingrese la clave de encriptación ";cin>>clave;
    encripta(clave);
    return 0;
}
