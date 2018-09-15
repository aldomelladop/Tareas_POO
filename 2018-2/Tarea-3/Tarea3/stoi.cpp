// stoi example
#include <iostream>   // std::cout
#include <string>     // std::string, std::stoi

int main ()
{
  
  std::string str_bin = "-10010110001";


  std::string::size_type sz;   // alias of size_t

  int i_bin = std::stoi (str_bin,nullptr,2);

  std::cout << str_bin << ": " << i_bin << '\n';

  return 0;
}