// tuple_cat example
#include <iostream>     // cout
#include <utility>      // pair
#include <string>       // string
#include <tuple>        // tuple, tuple_cat, get
#include <vector>

using namespace std;

int main ()
{
	string frase = "abcde";
	vector<int> enteros = {1,2,3,4,5};
 
  	tuple<pair<char,int>,pair<char,int>> my_tuple;
  	pair<char,int> mypair;

	for(int i=(enteros.size()-1);i>=0;i--)
	{ 
		mypair = make_pair(frase[i],enteros[i]);
		my_tuple= make_tuple(mypair.first,mypair.second);
	}

  auto myauto = tuple_cat ( my_tuple, tuple<int,char>() );

  cout << "myauto contains: " << '\n';
  cout << get<0>(myauto) << '\n';
  cout << get<1>(myauto) << '\n';
  cout << get<2>(myauto) << '\n';
  cout << get<3>(myauto) << '\n';

  return 0;
}