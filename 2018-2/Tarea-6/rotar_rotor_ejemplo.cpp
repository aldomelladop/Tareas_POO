//map<char,char> Rotor::rotaRotor(const char& c)
void Rotor::rotaRotor(const char& c)
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
    cout<<aux;
}
/*
    char x = c;
    map<char,char> aux[26];
    map<char,char> aux2=codificador;

    map<char,char>::iterator it = aux2.begin();

    for(aux2.find(x);it!=aux2.end(),it++)
    {
        aux.push_back(*it);
    }
    for(it;it!=aux2.find(x),it++)
    {
        aux.push_back(*it);
    }
*/

    //copy(codificador.find(x),codificador.end(),aux.begin());
    //copy_backward(codificador.begin(),codificador.find(aux),aux1.end());
    
//    return aux;   
//map<char,char> Rotor::rotaRotor(const char& c)
void Rotor::rotaRotor(const char& c)
{
    char x = c;
    pair<char,char> aux[26];
    map<char,char>::iterator it = codificador.begin();

    for(it;it!=codificador.end();it++)
    {
        if(codificador.find(x)!=codificador.end())
            {
                for(codificador.find(x);it!=codificador.end(),it++)
                {
                    aux.insert(*it);
                }
                for(codificador.end();it!=codificador.find(x);it--)
                {
                    aux.push_front(*it);
                }
            }
    }

/*
    char x = c;
    map<char,char> aux[26];
    map<char,char> aux2=codificador;

    map<char,char>::iterator it = aux2.begin();

    for(aux2.find(x);it!=aux2.end(),it++)
    {
        aux.push_back(*it);
    }
    for(it;it!=aux2.find(x),it++)
    {
        aux.push_back(*it);
    }
*/

    //copy(codificador.find(x),codificador.end(),aux.begin());
    //copy_backward(codificador.begin(),codificador.find(aux),aux1.end());
    
//    return aux;   
}