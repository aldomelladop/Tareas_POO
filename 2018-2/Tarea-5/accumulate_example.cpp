#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
 
 using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> w ={0,2,3,5,7,11,13,17,19,23};
 
    int sum = accumulate(v.begin(), v.end(), 0); //1+2+3+4+5+6+7+8+9+10
 
    cout << "sum: " << sum <<endl<< "product: " << product << '\n';
}