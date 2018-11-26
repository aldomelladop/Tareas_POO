#include <iostream>
#include <stdexcept>    // Domain_error
#include <algorithm>    // std::sort
#include <string>       // std::string
#include <vector>       // std::vector
#include <list>
#include <fstream>      // std::ifstream
#include <map>

/* Pendientes
    - Agregar do while
    - Revisar friend clases
*/

using namespace std;

class Rotor
    {
        //friend string encripta(const string& p);
    public:
        Rotor(){}
        string encripta(const string& p);
        string desencripta(const string& p);
        void invierte();
        Rotor(string p)
        {
            string  key = p;
            int num =  key.size();
            string::iterator it =  key.begin();

            if(num != 26)
            {
                throw domain_error("El largo del string es distinto de 26 ");
            }
            try
            {
                sort(  key.begin(),   key.end());
                if(adjacent_find(  key.begin(),   key.end())!=  key.end())
                {
                    throw domain_error("Existen elementos repetidos en la clave ingresada");
                }
                try
                {

                    string::iterator it1 = p.begin();
                    key.clear();

                    for(it1;it1!=p.end();it1++)
                    {
                          clave.push_back(toupper(*it1)); //Modifica la variable en private llamada clave?
                    }

                    //cout<< clave; 

                    //string  clave1 = p;
                    //int largo = clave.size();

                    for(int i=0;i<26;i++)
                      {
                        codificador.insert(make_pair(abecedario[i],clave[i]));
                      }
                      //revisa tamaño
                }
                catch(domain_error e2) {
                    cerr << e2.what() << endl;
                }
            }
            catch(domain_error e1) {
                cerr << e1.what() << endl;
            }
        }

    protected:
        string clave;
        const string abecedario = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        map<char,char> codificador;
    };


string Rotor::encripta(const string& s)
{
    string mensaje = s, aux;
    string::iterator it1 = mensaje.begin();

    for(it1;it1!=mensaje.end();it1++)
    {
          aux.push_back(toupper(*it1)); //Modifica la variable en private llamada clave?
    }

    string salida;
    string::iterator iter1 = aux.begin(); // Accedo a aux porque el mensaje ya esta en mayusculas
    map<char,char>::iterator iter2 = codificador.begin();

    for(iter1;iter1!=aux.end();iter1++)
        {
            if(codificador.find(*iter1)==codificador.end()) // Hace un push_back de los caracteres no mapeados en rotor e.g: ! , - , etc
            {
                salida.push_back(*iter1);
            }
            else
            {
                salida.push_back(codificador.find(*iter1)->second); // hace push_back de la traducción equivalente segun mapeo de rotor AA = QQ
            }
        }
    return salida;
}

string Rotor::desencripta(const string& s)
{
    map<char,char> decodificador;
    map<char,char>::iterator i = codificador.begin();

    for (i; i != codificador.end(); i++)
    
    {
        decodificador.insert(make_pair(i->second,i->first));

    }
    
    string mensaje = s, aux;
    string::iterator it1 = mensaje.begin();

    for(it1;it1!=mensaje.end();it1++)
    {
          aux.push_back(toupper(*it1)); //Modifica la variable en private llamada clave?
    }

    string salida;
    string::iterator iter1 = aux.begin(); // Accedo a aux porque el mensaje ya esta en mayusculas
    map<char,char>::iterator iter2 = decodificador.begin();

    for(iter1;iter1!=aux.end();iter1++)
        {
            if(decodificador.find(*iter1)==decodificador.end()) // Hace un push_back de los caracteres no mapeados en rotor e.g: ! , - , etc
            {
                salida.push_back(*iter1);
            }
            else
            {
                salida.push_back(decodificador.find(*iter1)->second); // hace push_back de la traducción equivalente segun mapeo de rotor AA = QQ
            }
        }
    return salida;
}

int main()
{
    int opcion=3;
    list<string> input;
    string word;

    cout<<"Ingrese un el número que contenga a la operación que desea realizar: "<<endl;
    cout<<"Ingrese un 1: si desea encriptar"<<endl;
    cout<<"Ingrese un 0: si desea dsencriptar"<<endl;
    cin>>opcion;

    if(opcion==1)
    {
        fstream in("MobyDick_Ch01.txt", fstream::in);
        fstream out("output.txt",fstream::out);

        /// noskipws = Do not skip whitespaces o while (in >> noskipws >> letter)
        /* hubiera sido util si la funcion encripta lo hiciera sobre un caracter individual
        sin embargo, como lo hace sobre un string o palabra, la solucion idonea es la siguiente:*/

         
        while (in >> word)
        {
            word = word + ' '; //adecuado para mostrar que esta recibiendo bien los elementos. No asi para que encripta pueda operar adecuadamente.
            input.push_back(word);
        }
    /*
        for(auto x:input)
        {
            cout<<x<<endl;
        }
    */

    ///*
        //// Lo que se tiene hasta ahora, es que se ingresará la  key a codificar, tal que con ella se hará la codificación de las palabras que se ingresan desde el texto
        string  key;
        key  = "QWERTYUIOPASDFGHJKLZXCVBNM";

        //cout<<"Ingrese la clave de encriptación ";cin>> key;

        Rotor r1( key);

        //QWERTYUIOPASDFGHJKLZXCVBNM

        list<string>::iterator it = input.begin();

        //cout<<"\nLa encriptación equivalente al texto ingresado es: ";

        for(it;it!=input.end();it++)
        {
            //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
            out<< r1.encripta(*it);
        }
        cout<<"\n Encriptación exitosa"<<endl;
    }
    else
    {
        fstream in("output.txt", fstream::in);
        fstream out("desencripta.txt",fstream::out);

        while (in >> word)
        {
            word = word + ' '; //adecuado para mostrar que esta recibiendo bien los elementos. No asi para que encripta pueda operar adecuadamente.
            input.push_back(word);
        }
    
        string  key;
        key  = "QWERTYUIOPASDFGHJKLZXCVBNM";

        Rotor r1( key);

        list<string>::iterator it = input.begin();

        for(it;it!=input.end();it++)
        {
            //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
            out<< r1.desencripta(*it);
        }
        cout<<"\n Desencriptación exitosa"<<endl;
    }
    return 0;
}
