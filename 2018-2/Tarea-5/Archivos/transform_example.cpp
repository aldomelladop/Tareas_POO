// transform algorithm example
#include <iostream>     // cout
#include <algorithm>    // transform
#include <list>       // vector
#include <functional>   // plus

using namespace std;


list<int> sumofList(list<int> l1,list<int> l2)
{
  list<int> suma = l2;
  transform (l1.begin(), l1.end(), suma.begin(), suma.begin(),plus<int>());
  //accumulate (l1.begin(), l1.end(), l2.begin(), l1.begin(),0);
  return suma;
}

int main () {
  list<int> foo,bar,ans;

  // set some values:
  for (int i=1; i<6; i++)
    {
      foo.push_back (i*10); // foo: 10 20 30 40 50
      bar.push_back((i*10)+1);// bar: 11 21 31 41 51     
    }


  // plus adds together its two arguments:
    ans = sumofList(bar,foo);

  cout<<"\nImprimiendo foo: ";
    for(auto x:foo)
    {
      cout<<x<<" ";
    }

  cout<<"\nImprimiendo bar: ";
    for(auto x:bar)
    {
      cout<<x<<" ";
    }

  cout<<"\nImprimiendo ans: ";
    for(auto x:ans)
    {
      cout<<x<<" ";
    }

  return 0;
}

/*

*/