// factorials (multiplies example)
#include <iostream>     // cout
#include <functional>   // multiplies
#include <numeric>      // partial_sum

using namespace std;

int main () {
  int numbers[11];
  int factorials[11];
  
  for (int i=0;i<11;i++) 
  	{
  		numbers[i]=i+1;
  		partial_sum (numbers, numbers+11, factorials, multiplies<int>());
  	}
      
  for (int i=0; i<11; i++)
    cout << numbers[i] << "! is " << factorials[i] << '\n';
  return 0;
}