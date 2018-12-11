#include <iostream>
#include <string>
#include <sstream>

using namespace std;
string look(string looksay);

int main()
{
    string looksay,ls;
    int j;
    looksay="1";
    ls=look(looksay);
    cout<<"Look and say "<<1<<": "<<looksay<<endl;
    cout<<"Look and say "<<2<<": "<<ls<<endl;
    for(j=0;j<28;j++)
    {ls=look(ls);
        cout<<"Look and say "<<j+3<<": "<<ls<<endl;
    }
    return 0;
}

string look(string looksay)
{
    string looksay2,contador,aa;
    int i,n,j,c=1;
    char a,b;
    n=looksay.length();
    for(i=0;i<=n;i++)
    {
        
        a=looksay[i];
        b=looksay[i+1];
        
        if(a==b){c=c+1;}
        else
        {
            contador=to_string(c);
            looksay2=looksay2+contador+looksay[i];
            c=1;
        }
    }
    //looksay=looksay2;
    return looksay2;
}