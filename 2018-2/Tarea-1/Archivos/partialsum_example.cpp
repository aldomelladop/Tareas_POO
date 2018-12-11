// partial_sum example
#include <iostream>     // cout
#include <functional>   // multiplies
#include <numeric>      // partial_sum
#include <vector>

using namespace std;

vector<int> llenastring()
{
    vector<int> numeros;

    for(int i=0;i<1001;i++) 
    {
      numeros.push_back(i);
    }

  return numeros;
}

int main () 
{
  
  vector<int> val,resultado;
  int largo;
  
  val = llenastring();
  largo = val.size();

  int result[largo];

  for(int i=0;i<val.size();i++)
  {
    partial_sum (val, val[largo], result ,multiplies<int>());
{
  vector<int> numeros;

  for(int i=0;i<1001;i++) 
  {
    numeros.push_back(i);
  }

  return numeros;
};
  }

  cout << "using default partial_sum: ";
  for (int i=0; i<val.size(); i++) 
  {
    cout << resultado[i] << ' '<<endl;
  }

/*  partial_sum (val, val+5, result, multiplies<int>());
  cout << "using functional operation multiplies: ";
  for (int i=0; i<5; i++) cout << result[i] << ' ';
  cout << '\n';
*/

  return 0;
}