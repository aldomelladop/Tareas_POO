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

	string  palabra;
	string  palabra1 = p;
	string abecedario = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string clave = {"QWERTYUIOPASDFGHJKLZXCVBNM"};
	string salida;

	string::iterator iter = palabra1.begin();
	for(iter;iter!=palabra1.end();iter++)
	{
	    palabra.push_back(toupper(*iter));
	}
 
 	cout<<"\nImprimiendo palabra: "<<palabra<<endl;

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

    string::iterator iter1 = palabra.begin();
    map<char,char>::iterator iter2 = codificador.begin();

	for(iter1;iter1!=palabra.end();iter1++)
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
	
	cout<<"\nLa palabra a codificar fue: "<<palabra<<"\nLa palabra codificada  fue: "<<salida<<endl;
	salida.clear();
}	

int main()
{
    encripta("Hola mundo 2018!");
    return 0;
}
