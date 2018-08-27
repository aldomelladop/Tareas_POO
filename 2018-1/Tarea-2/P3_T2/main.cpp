#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

//list posicion(list t)
//{
//
//    list<int> a;
//    list<char> b;
//
//    list<int>::iterator it1;
//    list<char>::iterator it2;
//
//    for(int i=0;i=<2850;i++)
//    {a.push_back(i);}
//
//    for(char i='a';i=<'z';i++)
//    {b.push_back(i);}
//
//    it1 = a.begin();
//    it2 = b.begin();
//
//    for(i=0;i<28;i++)
//    {
//        while(it2!=b.end())
//        {
//            while(*it1!=t[i])
//            {
//            pos_a.push_back(*it2);
//            it2++;
//            }
//        }
//    }
//    return pos_a;
//}


int main()
{

    list<int> a;
    list<char> b;

    list<int>::iterator it1;
    list<char>::iterator it2;

    for(int i=0;i<2851;i++)
    {a.push_back(i);}

    for(char i='a';i<='z';i++)
    {b.push_back(i);}


    for(int x:b){cout<<x<<endl;}

return 0;
}
