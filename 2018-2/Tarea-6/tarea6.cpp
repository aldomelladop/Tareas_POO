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
            string palabra = p;
            int num = palabra.size();
            string::iterator it = palabra.begin();

            if(num != 26)
            {
                throw domain_error("El largo del string es distinto de 26 ");
            }
            try
            {
                sort(palabra.begin(), palabra.end());
                if(adjacent_find(palabra.begin(), palabra.end())!=palabra.end())
                {
                    throw domain_error("Existen elementos repetidos en la palabra ingresada");
                }
                try
                {
                    
                    string::iterator it1 = p.begin();
                    palabra.clear();

                    for(it1;it1!=p.end();it1++)
                    {
                        palabra.push_back(toupper(*it1));
                    }

                    cout<<palabra;
                 
        //        encripta(palabra);
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
        string palabra;
        string clave = "QWERTYUIOPASDFGHJKLZXCVBNM";
        const string abecedario  = "ABCDEFGHIJLMNOPQRSTUVWXYZ";
        //list<pair<char,char>> salida {make_pair('A','Q'),make_pair('B','W'),make_pair('C','E'),make_pair('D','R'),make_pair('E','T'),make_pair('F','Y'),make_pair('G','U'),make_pair('H','I'),make_pair('I','O'),make_pair('J','P'),make_pair('K','A'),make_pair('L','S'),make_pair('M','D'),make_pair('N','E'),make_pair('F','G'),make_pair('P','H'),make_pair('Q','J'),make_pair('R','K'),make_pair('S','L'),make_pair('T','Z'),make_pair('U','X'),make_pair('V','C'),make_pair('W','V'),make_pair('X','B'),make_pair('Y','N'),make_pair('Z','M')};
        list<pair<char,char>> codifica;      
    };
/*
void Rotor::encripta(const string& p)
        {
            //pair<char,char> codificador; //codifica.first entrada () - codifica.second salida
            list<pair<char,char>> codificador;
            int largo = palabra.size();
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
    //Ingresando clave de cifrado
    Rotor r1("abcdefghijklmnopqrstuvwxyz");


    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     string s = "holacomoestas";
//     string::iterator iter1 = s.begin();
//     string::iterator iter2 = s.begin();
//     vector<int> vectorcontador;

//     int contador = 0;
//     for(int i = 0; i < s.size(); i++)
//     {
//         for (iter2; iter2 != s.end(); iter2++)
//         {
//             if(*(iter1) == *(iter2))
//             {
//                 contador++;
//                 cout << *(iter1) << endl;
//             }
//             else
//             {
//                 cout << "No esta" << endl;
//             }
//         }
//         iter1++;
//         iter2 = s.begin();
//         iter2 = iter2+i;
//         vectorcontador.push_back(contador);
//         contador = 0;
//     }

//     iter1 = s.begin();

//     for(auto x:vectorcontador)
//     {
//         cout << "La cantidad de letras " << *(iter1) <<" es "<< x << endl;
//         iter1++;
//     }

//     return 0;
// }