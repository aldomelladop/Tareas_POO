//ejemplo3.cpp

#include <iostream>
#include <stdexcept>

using namespace std;

class MFD {
public:
bool sign(){return signo;}
long int enter(){return entero;}
int cont(){return conta;}
void setSigno(bool);
void setEntero(long int);

private:
bool signo; // Toma valores true o false
long int entero; // Parte entera del MFD
int conta=0;
};
void MFD::setSigno(bool s){
    signo=s;
}
void MFD::setEntero(long int e){
    entero=e;
}

int main()
{
    bool sig;
    long int a,b,d;
    MFD prueba;
    cout << "Ingrese signo,1 positivo 0 negativo,entero y fraccion" << endl;
    cin>>sig>>a>>b;
    prueba.setSigno(sig);
    prueba.setEntero(a);

    cout << "el numero es" <<endl;
    cout << " signo (1 positivo 0 negativo)" << prueba.sign()<<endl;
    cout << "" << prueba.enter();
    return 0;
}
