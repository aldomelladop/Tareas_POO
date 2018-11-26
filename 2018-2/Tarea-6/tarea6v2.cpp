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
        string decripta(const string& p);
        //map<char,char> rotaRotor(const char& c);
        string rotaRotor(const char& c);
        void avanzaRotor(void);

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

    private:
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

string Rotor::decripta(const string& s)
{
    map<char,char> decodificador;
    map<char,char>::iterator i = codificador.begin();

    for (i; i != codificador.end(); i++)
    {
        decodificador.insert(make_pair(i->second,i->first));
    }

    string mensaje = s;
    string::iterator it1 = mensaje.begin();

    string salida;
    map<char,char>::iterator iter2 = decodificador.begin();

    for(it1;it1!=mensaje.end();it1++)
        {
            if(decodificador.find(*it1)==decodificador.end()) // Hace un push_back de los caracteres no mapeados en rotor e.g: ! , - , etc
            {
                salida.push_back(*it1);
            }
            else
            {
                salida.push_back(decodificador.find(*it1)->second); // hace push_back de la traducción equivalente segun mapeo de rotor AA = QQ
            }
        }
    return salida;
}

string Rotor::rotaRotor(const char& c)
{
    char x = toupper(c);
    //cout<<x<<endl;

    string aux;
    string::iterator it=clave.begin();

    for(it;it!=clave.end();it++)
    {
/*        if(*it=x)
        {
            for(it;it!=clave.end();it++)
            {
             //   copy(it,clave.end(),aux.begin());
             // copy_backward(clave.begin(),it,aux.end());
                cout<<*it<<" ";
            }
        }
        else
        {
            cout<<"Saliendo";
            break;
*/
        cout<<*it<<" ";
        }
    }
    cout<<aux;
    return aux;
}



int main()
{
    int opcion=3;
    list<string> input;
    string word;
    string  key;
    key  = "QWERTYUIOPASDFGHJKLZXCVBNM";
    Rotor r1( key);

    cout<<"Ingrese un el número que contenga a la operación que desea realizar: "<<endl;
    cout<<"Ingrese un 0: si desea encriptar"<<endl;
    cout<<"Ingrese un 1: si desea decriptar"<<endl;
    cout<<"Ingrese un 2: si desea rotar el rotor"<<endl;

    for(int i=0;i<26;i++){if(i==0 || i==25){cout<<endl;}else{cout<<"-";}}
    cout<<"\nOpción: ";cin>>opcion;

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

        //cout<<"Ingrese la clave de encriptación ";cin>> key

        list<string>::iterator it = input.begin();

        //cout<<"\nLa encriptación equivalente al texto ingresado es: ";

        for(it;it!=input.end();it++)
        {
            //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
            out<< r1.encripta(*it);
        }
        cout<<"\n Encriptación exitosa"<<endl;
    }
    else if(opcion==1)
    {
        fstream in("output.txt", fstream::in);
        fstream out("desencripta.txt",fstream::out);

        while (in >> word)
        {
            word = word + ' '; //adecuado para mostrar que esta recibiendo bien los elementos. No asi para que encripta pueda operar adecuadamente.
            input.push_back(word);
        }

        list<string>::iterator it = input.begin();

        for(it;it!=input.end();it++)
        {
            //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
            out<< r1.decripta(*it);
        }
        cout<<"\n Desencriptación exitosa"<<endl;
    }
    else
    {
        r1.rotaRotor('K');
    }
    return 0;
}
