void Rotor::rotaRotor(const char& c)
{
    char x = toupper(c);
    list<char> reves[26];
    string::iterator it=clave.begin();
    list<char>::iterator it1 = reves.begin();

    cout<<"\nImprimiendo clave: "<<clave<<endl;

    for(it;it!=clave.end();it++)
    {
        cout<<*it<<endl;
        if(x==*it)
        {   
            it1 = it;
                for(it;it!=clave.end();it++)
                {
                    reves.push_back(*it);
                }           
                for(clave.begin();it1;it1++)
                {
                    reves.push_fron(*it);
                }
//                it1 = it;
//                cout<<"se rompio aquí"<<endl;
//                copy(it, clave.end(), claverotada.end());
                
/*
                reverse(clave.begin(),clave.end());
                cout<<"\nClave: "<<clave<<endl;
                cout<<"\nClave Rotada: "<<clave<<endl;
                reverse(claverotada.begin(),claverotada.end());
                copy(clave.begin(),it1,claverotada.begin());
*/
        }
    }
//    cout<<claverotada;
    for(auit)
}