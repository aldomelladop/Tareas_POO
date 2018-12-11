
// C++ program to check if a number is pandigital 
// in given base. 
#include<bits/stdc++.h> 
using namespace std; 
  
// Return true if n is pandigit else return false. 
bool checkPandigital(int b, char n[]) 
{ 
    // Checking length is less than base 
    if (strlen(n) < b) 
        return false; 
  
    bool hash[b]; 
    memset(hash, false, sizeof(hash)); 
  
    // Traversing each digit of the number. 
    for (int i = 0; i < strlen(n); i++) 
    { 
        // If digit is integer 
        if (n[i] >= '0' && n[i] <= '9') 
            hash[n[i] - '0'] = true; 
  
        // If digit is alphabet 
        else if (n[i] - 'A' <= b - 11) 
            hash[n[i] - 'A' + 10] = true; 
    } 
  
    // Checking hash array, if any index is 
    // unmarked. 
    for (int i = 0; i < b; i++) 
        if (hash[i] == false) 
            return false; 
  
    return true; 
} 
  
// Driven Program 
int main() 
{ 
    int b = 13; 
    char n[] = "1298450376ABC"; 
  
    (checkPandigital(b, n))? (cout << "Yes" << endl): 
                             (cout << "No" << endl); 
  
    return 0; 
} 