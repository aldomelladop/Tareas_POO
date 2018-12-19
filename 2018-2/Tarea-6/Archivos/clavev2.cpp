#include <iostream>
#include <stdexcept>    // Domain_error
#include <algorithm>    // std::sort
#include <string>       // std::string
#include <vector>       // std::vector
#include <list>
#include <map>

using namespace std;

void encripta(const string& p)
{   
	string  clave1 = p;
    int largo = clave.size();
    
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
