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
        char encripta(const char& p);
        char decripta(const char& s);
        string rotaRotor(const char& c);
        string avanzaRotor();

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
                    for(int i=0;i<26;i++)
                      {
                        codificador.insert(make_pair(abecedario[i],clave[i]));
                      }
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

class Enigma : public Rotor
{
    public:
        Enigma(){};
        Enigma(list<pair<char,char>> lista) //(1,'a')
        {
            //Abriendo texto  de entrada
            char character;
            string  inputin,ref_out,output,aux,aux1,aux2;
            fstream in("test.txt", fstream::in);
            fstream out("output.txt",fstream::out);


            /// noskipws = Do not skip whitespaces o while (in >> noskipws >> letter)
            /* hubiera sido util si la funcion encripta lo hiciera sobre un caracter individual
            sin embargo, como lo hace sobre un string o palabra, la solucion idonea es la siguiente:*/

            int j=1;
            list<pair<char,char>>::iterator itpar = lista.begin();

            for(itpar;itpar!=lista.end();itpar++)
            {
                if(((*itpar).first)=='1')
                {
                    key = rotor1;
                }
                else if(((*itpar).first)=='2')
                {
                    key = rotor2;
                }
                else if(((*itpar).first)=='3')
                {
                    key = rotor3;
                }
                else if(((*itpar).first)=='4')
                {
                    key = rotor4;
                }
                else if(((*itpar).first)=='5')
                {
                    key = rotor5;
                }

                //cout<<"\nImprime clave: "<<key<<endl;
                if(j==1)
                {
                    Rotor rotor_lento(key);
                    clave1rotada = rotor_lento.rotaRotor((*itpar).second);
                    cout<<"\nRotor lento:  "<<clave1rotada;
                }
                else if(j==2)
                {
                    Rotor rotor_medio(key);
                    clave2rotada = rotor_medio.rotaRotor((*itpar).second);
                    cout<<"\nRotor  medio: "<<clave2rotada;
                }
                else if(j==3)
                {
                    Rotor rotor_rapido(key);
                    clave3rotada = rotor_rapido.rotaRotor((*itpar).second);
                    cout<<"\nRotor rápido: "<<clave3rotada<<endl;
                }
            j++;
            }

            cout<<"\nAsignación de clave a iteradores"<<endl;

            Rotor rotor_lento(clave1rotada);
            Rotor rotor_medio(clave2rotada);
            Rotor rotor_rapido(clave3rotada);
            Rotor reflector(key_ref);

            /*Comienza la codificacion pasando primero por el rotor rapido. Lo que se hace en primera
            instancia es leer el archivo que contiene las palabras. */

            cout<<"\nLeyendo archivo de entrada"<<endl;
            while (in >> noskipws >> character)
            {
                inputin.push_back(character);
            }

            string::iterator itin = inputin.begin();

            cout<<"\nSe procede a codificar por el rotor rapido"<<endl;

            for(itin;itin!=inputin.end();itin++)
            {
                aux.push_back(rotor_rapido.encripta(*itin));
            }

            string::iterator itaux = aux.begin();

            cout<<"Se procede a codificar por el rotor medio"<<endl;
            for(itaux;itaux!=aux.end();itaux++)
            {
                aux1.push_back(rotor_medio.encripta(*itaux));
            }

            string::iterator itaux1 = aux1.begin();

            cout<<"Se procede a codificar por el rotor lento"<<endl;
            for(itaux1;itaux1!=aux1.end();itaux1++)
            {
                aux2.push_back(rotor_lento.encripta(*itaux1));
            }

            string::iterator itaux2 = aux2.begin();

            cout<<"Se procede a codificar por el reflector"<<endl;

            for(itaux2;itaux2!=aux2.end();itaux2++)
            {
                ref_out.push_back(reflector.encripta(*itaux2));
            }

            aux.clear(),aux1.clear(),aux2.clear(); //Se reinician las variables, borrando los elementos, esto con la finalidad de poder reutilizarlos en el regreso del codificador.

            string::iterator itref= ref_out.begin();

            cout<<"Se procede a codificar por el rotor lento"<<endl;

            for(itref;itref!=ref_out.end();itref++)
            {
                //cout<<*itref;
                aux2.push_back(rotor_lento.decripta(*itref));
            }

            itaux2 = aux2.begin();

            cout<<"Se procede a codificar por el rotor mediano"<<endl;

            for(itaux2;itaux2!=aux2.end();itaux2++)
            {
                aux1.push_back(rotor_medio.decripta(*itaux2));
            }

            itaux1 = aux1.begin();

            cout<<"Se procede a codificar por el rotor rapido"<<endl;

            for(itaux1;itaux1!=aux1.end();itaux1++)
            {
                aux.push_back(rotor_rapido.decripta(*itaux1));
            }

            for(auto x:aux)
            {
                out<<x;
            }
        }

    private:
    ///Van en el private
    string key,clave3rotada,clave2rotada,clave1rotada;
    const string& key_ref   = "IXUHFEZDAOMTKQJWNSRLCYPBVG";
    const string& rotor1    = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    const string& rotor2    = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    const string& rotor3    = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    const string& rotor4    = "QAZWSXEDCRFVTGBYHNUJMIKOLP";
    const string& rotor5    = "HGTYUJMNBCFRIKCDEOLXSWPZAQ";
};

char Rotor::encripta(const char& p)
{
    char aux,salida,mensaje = p; //a
    aux = toupper(mensaje); // A

    map<char,char>::iterator iter2 = codificador.begin();

    if(codificador.find(aux)==codificador.end()) // Hace un push_back de los caracteres no mapeados en rotor e.g: ! , - , etc
        {
            salida  = aux;
        }
    else
        {
            salida = codificador.find(aux)->second;; // busca la traducción equivalente segun mapeo de rotor AA = QQ
        }
    return salida;
}

char Rotor::decripta(const char& s)
{
    map<char,char> decodificador;
    map<char,char>::iterator i = codificador.begin();

    for (i; i != codificador.end(); i++)
    {
        decodificador.insert(make_pair(i->second,i->first));
    }

    char aux = s,salida;

    if(decodificador.find(aux)==decodificador.end()) // Hace un push_back de los caracteres no mapeados en rotor e.g: ! , - , etc
        {
            salida  = aux;
        }
    else
        {
            salida = decodificador.find(aux)->second;; // busca la traducción equivalente segun mapeo de rotor AA = QQ
        }

    return salida;
}

string Rotor::rotaRotor(const char& c)
{
    char x = toupper(c);
    string aux;
    string::iterator it,iter2Final;
    string::iterator iter = clave.begin();

    it =  find(clave.begin(), clave.end(), x);
    iter2Final = it;

    for(it;it!=clave.end();it++)
    {
        aux.push_back(*it);
    }
    for(iter;iter!=iter2Final;iter++)
    {
        aux.push_back(*iter);
    }

    return aux;
}

string Rotor::avanzaRotor()
{
    list<char> aux;
    string aux1;
    string::iterator iter = clave.begin();

    for(iter;iter!=clave.end();iter++)
    {
        if(iter!=clave.end())
        {
            aux.push_front(*iter);
        }
        else
        {
            aux.push_back(*clave.begin());
        }
    }

    clave.clear();

    for(auto x:aux)
    {
        clave.push_back(x);
    }
    return clave;
}

int main()
{
    char n1errotor,n2orotor,n3errotor,letra1,letra2,letra3;

    cout<<"\nEscoja el numero de los rotores a usar: "<<endl;
    cin>>n1errotor>>n2orotor>>n3errotor;
    cout<<"Escoja la primera letra de la clave a utilizar para cada rotor: "<<endl;
    cin>>letra1>>letra2>>letra3;
    cout<<endl;

    string numeros = {n1errotor,n2orotor,n3errotor};
    string letras = {letra1,letra2,letra3};

    pair<char,char> par1,par2,par3;
    list<pair<char,char>> mylist ={par1,par2,par3};
    list<pair<char,char>>::iterator it=mylist.begin();

    for(int i=0;i<numeros.size();i++)
      {
          (*it) = make_pair(numeros[i],letras[i]);
          cout<<"enigma"<<i<<" ("<<(*it).first<<","<<(*it).second<<")"<<endl;
          it++;
      }

    // Llamando a Enigma

    Enigma e1(mylist);

    return 0;
}
