// map::find
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main ()
{
  map<char,char> mymap;
  map<char,char>::iterator it;
  string abecedario = "acd";
  string clave = "QWE";

  int largo = abecedario.size();

  for(int i=0;i<largo;i++)
  {
  mymap.insert(make_pair(abecedario[i],clave[i]));
  }


  /*
  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);
  */
  
  // print content:
  cout << "elements in mymap:" << '\n';
  string::iterator iter = abecedario.begin();
  for(auto x:mymap)
  {
  cout<< mymap.find(*iter)->second << '\n';
  iter++;
  //cout << "c => " << mymap.find('c')->second << '\n';
  //cout << "d => " << mymap.find('d')->second << '\n';
  }
  return 0;
}