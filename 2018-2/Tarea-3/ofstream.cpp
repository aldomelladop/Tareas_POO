// ofstream constructor.
#include <fstream>      // std::ofstream

using namespace std;

int main () {

  ofstream ofs ("test.txt", ofstream::out);

  ofs << "lorem ipsum safasfas" ;

  ofs.close();

  return 0;
}