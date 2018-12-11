#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>

using namespace std;
 
int main()
{
    int num= 21;

    vector<int> v;

    for(int i=1;i<num;i++)
    {
        v.push_back(i);
    }
 
    cout << "The first 10 even numbers are: ";
    partial_sum(v.begin(), v.end(), 
                     ostream_iterator<int>(cout, " "));
    cout << '\n';
 
    partial_sum(v.begin(), v.end(), v.begin(), multiplies<int>());
    cout << "The first 10 powers of 2 are: ";
    for (auto n : v) {
        cout << n << " ";
    }

    cout << '\n';
}