// accessing mapped values
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <tuple>        // std::tuple, std::get, std::tie, std::ignore


using namespace std;
int main ()
{

  string frase = "abcde";
  string numeros = "12345";
  //tuple<pair<char,char>> mytuple;
  pair<char,char> par1,par2,par3,par4;
  list<pair<char,char>> mylist ={par1,par2,par3,par4};
  list<pair<char,char>>::iterator it=mylist.begin();

  for(int i=0;i<numeros.size();i++)
  { 
      //cout<<"("<<frase[i]<<","<<numeros[i]<<")"<<endl;
      (*it) = make_pair(frase[i],numeros[i]);
      cout<<"par"<<i<<" ("<<(*it).first<<","<<(*it).second<<")"<<endl;    
      it++;
  }
  
  cout<<endl;

  

/*  int i= 0;
  for(it;it!=mylist.end();it++)
  {

    cout<<"("<<(*(it)).first<<","<<(*(it)).second<<")"<<endl;
  }
*/


  //cout<<"("<<(get<0>(mytuple)).first<<","<<(get<0>(mytuple)).second<<")"<<endl;
  //cout<<"("<<(get<1>(mytuple)).first<<","<<(get<1>(mytuple)).second<<")"<<endl;
  /*cout<<"("<<(get<2>(mytuple)).first<<","<<(get<2>(mytuple)).second<<")"<<endl;
  cout<<"("<<(get<3>(mytuple)).first<<","<<(get<3>(mytuple)).second<<")"<<endl;
  cout<<"("<<(get<4>(mytuple)).first<<","<<(get<4>(mytuple)).second<<")"<<endl;
  */
  return 0;
}