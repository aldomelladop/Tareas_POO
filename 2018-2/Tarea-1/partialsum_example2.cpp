// partial_sum example
#include <iostream>     // cout
#include <functional>   // multiplies
#include <numeric>      // partial_sum
#include <vector>

using namespace std;

int main () {
  vector<int> val,result;

  int j = 1001;
  
  partial_sum (val, val+j, result, multiplies<int>());
  
  cout << "using functional operation multiplies: ";

  for (int i=0; i<j; i++) cout << result[i] << ' ';
  cout << '\n';

  return 0;
}