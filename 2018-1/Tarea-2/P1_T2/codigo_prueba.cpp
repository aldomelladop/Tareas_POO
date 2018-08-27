#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

/** “EnunlugardelaManchadecuyonombrenoquieroacordarme” **/
/** “ErcoocndhnqoueaournldmidlaebeauMcrrrgaueomanynae” **/

string escitala(const vector<string>& texto, const unsigned int vueltas)
{
    // & va a la dirección en memoria. No lo toques, no le hagas nada, solo verlo y copiarlo.

    vector<string> aux=texto;
    string text,auxt;

    int j=vueltas,r=0,len,s=0,m=0,lent;

    m = lent/vueltas;
    r = lent%vueltas;
    s = vueltas-r;

    for(auto x:aux){text=text+x;}
    lent= text.size();

    string::iterator it1=text.begin(),it2 =text.begin();

    advance(it2,j);

    for(it1;it1!=it2;it1++)
    {
        for(int k=0;k<lent;k=k+vueltas)
        {
            auxt=auxt + *(it1+k);
        //    cout<<"-----"<<auxt<<endl;
        }
    }
    //cout<<auxt<<endl;

    return auxt;
}

int main() {
unsigned int lados;
int lent;

cout << "Ingrese el número de lados: ";
cin >> lados;

cout << "Ingrese la frase a codificar (termine con ^D): ";

vector<string> texto;
string temp,esto;

    while (cin >> temp)
    {texto.push_back(temp);}

cout<<"A continuación palabra sin espacios"<<endl;

esto = escitala(texto, lados);

cout<<"La frase codificada es: "<<esto<<endl;

return 0;
}