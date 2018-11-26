#include <algorithm>
#include <iostream>
#include <vector>
 
 using namespace std;

int main()
{
    vector<int> from_vector;
    vector<int> ejemplo = {10,11,12,13,14};

    for (int i = 0; i < 10; i++) {
        from_vector.push_back(i);
    }
  
    cout<<"\nImprimiento elementos de from_vector: ";

    for(auto x:from_vector)
    {
      cout<<" "<<x;
    }
    vector<int> to_vector(15);
 

    /*    dado que necesito copiar desde una letra en particular, todos los elementos posteriores (De x en adelante) y luego, 
    los previos a dicha letra (De x hacia atrás), en otro vector, me valgo primero */

    cout<<"\n\nUsando copy";
    copy(from_vector.begin(), from_vector.end(), to_vector.begin());
    copy_backward(ejemplo.begin(),ejemplo.end(),to_vector.end());
 
    cout << "\nto_vector contains: ";
    for (auto i: to_vector) {
        cout << i << " ";
    }
    
    
 }