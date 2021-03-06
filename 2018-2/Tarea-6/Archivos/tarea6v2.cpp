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
        string rotaRotor(const char& c);
        string avanzaClave();
        void avanzaRotor(Rotor rotorejemplo(string claveejemplo),string claverotor);

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
        string clave,claverotada;
        const string abecedario = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        map<char,char> codificador;
    };

class Enigma : public Rotor
{
    public:
        Enigma(){};
        Enigma(list<pair<char,char>> lista) //(1,'a')
        {
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
                    cout<<"\nRotor lento: "<<clave1rotada;
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

        }

    private:
    ///Van en el private
    string key,clave1rotada,clave2rotada,clave3rotada;
    const string& reflector = "IXUHFEZDAOMTKQJWNSRLCYPBVG";
    const string& rotor1    = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    const string& rotor2    = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    const string& rotor3    = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    const string& rotor4    = "QAZWSXEDCRFVTGBYHNUJMIKOLP";
    const string& rotor5    = "HGTYUJMNBCFRIKCDEOLXSWPZAQ";
};

string Rotor::encripta(const string& s)
{
    string mensaje = s, aux;
    string::iterator it1 = mensaje.begin();

    for(it1;it1!=mensaje.end();it1++)
    {
          aux.push_back(toupper(*it1)); //Aux es el mensaje convertido a mayusculas
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

string Rotor::avanzaClave()
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
    return claverotada;
}

void Rotor::avanzaRotor(Rotor rotorAavanzar(string algo),string algo)
{
    string aux=algo;
    Rotor rotorsalida(),rotorauxiliar(aux);

    claverotada = rotorauxiliar.avanzaClave();

    rotorAavanzar(claverotada);
}

int main()
{
    int opcion;
    char n1errotor,n2orotor,n3errotor,letra1,letra2,letra3;
    list<string> inputin,inputout;
    list<pair<char,char>> opciones;
    string word, key,rotor1,rotor2,rotor3,rotor4,rotor5;

    //Abriendo texto  de entrada

        fstream in("MobyDick_Ch01.txt", fstream::in); ///RECORDAR QUE CAMBIE EL NOMBRE
        fstream out("output.txt",fstream::out);

        /// noskipws = Do not skip whitespaces o while (in >> noskipws >> letter)
        /* hubiera sido util si la funcion encripta lo hiciera sobre un caracter individual
        sin embargo, como lo hace sobre un string o palabra, la solucion idonea es la siguiente:*/

        while (in >> word)
        {
            word = word + ' '; //adecuado para mostrar que esta recibiendo bien los elementos. No asi para que encripta pueda operar adecuadamente.
            inputin.push_back(word);
        }

        list<string>::iterator itin = inputin.begin();

    //Abriendo texto de salida
        fstream in1("output.txt", fstream::in);
        fstream out1("desencripta.txt",fstream::out);

        while (in >> word)
        {
            //word = word + ' '; //adecuado para mostrar que esta recibiendo bien los elementos. No asi para que encripta pueda operar adecuadamente.
            inputout.push_back(word);
        }

        list<string>::iterator itout = inputout.begin();

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

        key = "QWERTYUIOPASDFGHJKLZXCVBNM";

        Rotor r1(key);
        cout<<"\nIngrese el número de la operación que desea realizar: "<<endl;
        cout<<"Ingrese un 0: si desea encriptar"<<endl;
        cout<<"Ingrese un 1: si desea decriptar"<<endl;
        cout<<"Ingrese un 2: si desea rotar el rotor"<<endl;
        cout<<"Ingrese un 3: si desea avanzar el rotor"<<endl;

        for(int i=0;i<26;i++){if(i==0 || i==25){cout<<endl;}else{cout<<"-";}}
        cout<<"\nOpción: ";cin>>opcion;

        switch(opcion)
        {

            case(0):

           {
                for(itin;itin!=inputin.end();itin++)
                {
                    cout<< *itin; //Despliega la encriptación del texto ingresado
                    out<< r1.encripta(*itin);
                }
                cout<<"\n Encriptación exitosa"<<endl;
                break;
            }
            case(1):
            {
                for(itout;itout!=inputout.end();itout++)
                {
                    //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
                    out<< r1.decripta(*itout);
                }
                cout<<"\n Desencriptación exitosa"<<endl;
                break;
            }
            case(2):
            {
                char x;
                cout<<"\nIngrese la primera letra de su clave: ";
                cin>>x;
                x = toupper(x);

                string aux = r1.rotaRotor(x);
                cout<<aux;

                Rotor r2(aux);

                for(itin;itin!=inputin.end();itin++)
                {
                    //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
                    out<< r2.encripta(*itin);
                }
                cout<<"\n Encriptación exitosa"<<endl;
                break;
            }
            case(3):
            {

                Rotor r2(r1.avanzaRotor());

                for(itin;itin!=inputin.end();itin++)
                {
                    //cout<< r1.encripta(*it); //Despliega la encriptación del texto ingresado
                    out<< r2.encripta(*itin);
                }
                cout<<"\n Encriptación exitosa"<<endl;
                break;
            }
        }
    return 0;
}
