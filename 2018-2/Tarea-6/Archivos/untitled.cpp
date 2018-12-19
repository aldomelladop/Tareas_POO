#include <iostream>
#include <string>
#include <algorithm>

 using namespace std;

int main()
{  
    string s = "HOLA MUNDO";
    cout << *(find(s.begin(), s.end(),' ')) << endl;
    return 0;
}