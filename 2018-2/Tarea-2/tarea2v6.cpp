#include <iostream>
#include <vector>

using namespace std;

void countandSay(vector<int> lass,int n)
{
	int l,counter =1;
	vector <int> ssal,ds;
    lass.push_back(1);
	lass.push_back(1);

	ssal = lass;
	ds = ssal;
	lass.clear();

	vector<int>::iterator it=ssal.begin();

	for(it;it<ssal.end();it++)
            {
				if(*(it)==*(it+1) && (it)!=ssal.end()-1)
                {
//                    cout<<"\nentra al if"<<endl;
                   // cout<<"valor del iterador: "<<*it<<endl;
                    counter++;
                }
                else if(it==ssal.end()-1) //en caso contrario, haz una copia de los elementos almacenados en el vector, borra el vector actual
                {
//                  cout<<"\nEntra al else if"<<endl;
                    //cout<<"valor del iterador: "<<*it<<endl;
                    lass.push_back(counter);
                    lass.push_back(*it);
                    counter=1;
                    continue;
                }
            }
	    ds = lass;
	    ssal= lass;
	    for(auto x:ds){cout<<x;}
}


int main()
{
	int n;
	vector <int> lass; //lass = look and say sequence
    lass.push_back(1);

	cout<<"Ingrese el nivel de la secuencia Look and Say (Lass) hasta el cual desea mostrar: ";
	cin>>n;

    cout<<"\nEs la secuencia correspondiente a la línea: \n"<<endl;

	for(int j=1;j<=n;j++)
	{
		cout<<"\nL"<<j<<": ";
        if(j==1)
        {
            for(auto x:lass){cout<<x;}
            lass.clear();
        }
        else if(j==2)
        {
            lass.push_back(11);
            for(auto x:lass){cout<<x;}
            lass.clear();
        }
        else
        {
		countandSay(lass,n);
        }

    }

	return 0;
}
