#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

/** “EnunlugardelaManchadecuyonombrenoquieroacordarme” **/
/** “ErcoocndhnqoueaournldmidlaebeauMcrrrgaueomanynae” **/

string escitala(const vector<string>& texto, const unsigned int vueltas)
{
    vector<string> aux=texto;
    string text,auxt;

    int j=vueltas,lent;

    for(auto x:aux){text=text+x;}

    string::iterator it1=text.begin(),it2 =text.begin();
    advance(it2,j);
    lent = text.size();

    for(it1;it1!=it2;it1++)
    {
        for(int k=0;k<lent;k=k+vueltas)
        {auxt=auxt + *(it1+k);}
    }

    return auxt;
}

int main() {
unsigned int lados;
int lent;

cout << "Ingrese el numero de lados: ";
cin >> lados;
cout << "Ingrese la frase a codificar (termine con ^D): ";

vector<string> texto;
string temp;

    while (cin >> temp)
    {texto.push_back(temp);}

cout<< "La frase codificada es: " <<escitala(texto,lados)<<endl;

return 0;
}