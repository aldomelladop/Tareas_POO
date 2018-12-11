// ifstream constructor.
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream

using namespace std;

int main () 
{

ifstream read("salida.txt");
int lines;
int c1[lines],c2[lines];
read>>lines;//number of lines
cout<<"Lines: "<<lines;

for(int i=1;i<=lines;i++)
{read>>c1[i]>>c2[i];
	cout<<"\nLinea: "<<i<<"\t";
	cout<<"c1 "<<c1[i]<<" - "<<"c2 "<<c2[i]<<endl;
}

  return 0;
}