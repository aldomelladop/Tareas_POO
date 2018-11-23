#include <iostream>
#include <stdexcept>    // Domain_error
#include <algorithm>    // std::sort
#include <string>       // std::string
#include <vector>       // std::vector
#include <list>
#include <map>

using namespace std;

class Rotor
    {
    public:
        Rotor(){}
        Rotor(string p)
        {
            string  clave = p;
            int num =  clave.size();
            string::iterator it =  clave.begin();

            if(num != 26)
            {
                throw domain_error("El largo del string es distinto de 26 ");
            }
            try
            {
                sort( clave.begin(),  clave.end());
                if(adjacent_find( clave.begin(),  clave.end())!= clave.end())
                {
                    throw domain_error("Existen elementos repetidos en la  clave ingresada");
                }
                try
                {
                    
                    string::iterator it1 = p.begin();
                     clave.clear();

                    for(it1;it1!=p.end();it1++)
                    {
                         clave.push_back(toupper(*it1));
                    }

                    cout<< clave;
                 
        //        encripta( clave);
                }
                catch(domain_error e2) {
                    cerr << e2.what() << endl;
                }
            }
            catch(domain_error e1) {
                cerr << e1.what() << endl;
            }
        }

    private:
        string  clave;
        const string abecedario  = "ABCDEFGHIJLMNOPQRSTUVWXYZ";
        //list<pair<char,char>> salida {make_pair('A','Q'),make_pair('B','W'),make_pair('C','E'),make_pair('D','R'),make_pair('E','T'),make_pair('F','Y'),make_pair('G','U'),make_pair('H','I'),make_pair('I','O'),make_pair('J','P'),make_pair('K','A'),make_pair('L','S'),make_pair('M','D'),make_pair('N','E'),make_pair('F','G'),make_pair('P','H'),make_pair('Q','J'),make_pair('R','K'),make_pair('S','L'),make_pair('T','Z'),make_pair('U','X'),make_pair('V','C'),make_pair('W','V'),make_pair('X','B'),make_pair('Y','N'),make_pair('Z','M')};
        list<pair<char,char>> codifica;      
    };
/*
void Rotor::encripta(const string& p)
        {
            //pair<char,char> codificador; //codifica.first entrada () - codifica.second salida
            list<pair<char,char>> codificador;
            int largo =  clave.size();
            string::iterator iter1=p.begin();
            for(int i=0;i<largo;i++)
              {
                codificador.push_back(make_pair(abecedario[i],clave[i]));
              }
            for(auto x:codificador)
            {
                cout<<"("<<x.first<<","<<x.second<<")"<<endl;
            }
        }
*/

int main()
{   

    //// Lo que se tiene hasta ahora, es que se ingresará la clave a codificar, tal que con ella se hará la codificación de las palabras que se ingresan desde el texto
    string clave;
    cout<<"Ingrese la clave de encriptación ";cin>>clave;
    Rotor r1(clave);
    return 0;
}