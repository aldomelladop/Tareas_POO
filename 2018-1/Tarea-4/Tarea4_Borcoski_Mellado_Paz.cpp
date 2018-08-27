#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class MFD {
    private:
        bool signo; // Toma valores true o false
        long int entero; // Parte entera del MFD
        long int fraccion; // Parte fraccional del MFD
        long int exponente; // Se utiliza base 10
    public:
        /* Aun no lo tenemos*/ MFD(bool,long int,long int,long int);
        //Recibe un numero entero
        MFD(int);
        //Recibe un numero double
        MFD(double);
        //Funciones que retornar los valores
        bool getSigno();
        long int getEntero();
        long int getFraccion();
        long int getExponente();
        //Funciones que modifican los valores (no retornan nada, solo modifican)
        void setSigno(bool);
        void setEntero(long int);
        void setFraccion(long int);
        void setPotencia(long int);
        //Funcion que imprime el numero en notacion exponencial
        void imprime();
        //Funcion que convierte el numero a double
        double toDouble();
        //Funcion que convierte el numero a un string
        string toString();
        // Multiplicacion
        MFD operator *  (MFD);

};
MFD::MFD(bool s,long int e,long int f,long int p){
    signo=s;
    entero=e;
    fraccion=f;
    exponente=p;
}
MFD::MFD(double numero){
    signo = true;
    if(numero<0){
        signo = false;
    }
    entero = numero;
    numero = numero - entero;

    fraccion = numero * 1000000;
    exponente = 0;

    while(numero < 1){
    numero = numero*10;
    exponente--;
    entero = entero*10;
    }
    exponente++;
    entero = entero/10;

    fraccion = numero * 100000;
}
MFD::MFD(int numero){
    signo = 1;
    if(numero<0){
        signo = 0;
    }
    entero = numero;
    fraccion = 0;
    exponente = 0;

}
bool MFD::getSigno(){
    return signo;
}
long int MFD::getEntero(){
    return entero;
}
long int MFD::getFraccion(){
    return fraccion;
}
long int MFD::getExponente(){
    return exponente;
}

void MFD::setSigno(bool s)
{
    signo=s;
}
void MFD::setEntero(long int e)
{
    entero=e;
}
void MFD::setFraccion(long int f)
{
    fraccion=f;
}
void MFD::setPotencia(long int p)
{
    exponente=p;
}
void MFD::imprime(){
    if(signo){
        cout<<entero<<"."<<fraccion<<"E"<<exponente<<endl;
    }
    else{
        cout<<"-"<<entero<<"."<<fraccion<<"E"<<exponente<<endl;
    }
}
double MFD::toDouble(){
    double doble;
    double aux_fraccion=double(fraccion);
    double aux_entero=double(entero);
    while(aux_fraccion>=1)
    {
        aux_fraccion/=10;
    }
    if(signo)
    {
         doble=(aux_entero+aux_fraccion)*pow(10,exponente);
    }
    else
    {
         doble=-(aux_entero+aux_fraccion)*pow(10,exponente);
    }
int dig_entero=0;
int dig_fraccion=0;
    while (entero) {
        entero /= 10;
        dig_entero++;
    }
    while (fraccion) {
        fraccion /= 10;
        dig_fraccion++;
    }
    if(dig_entero+dig_fraccion<=6)
    {
         return doble;
    }
    else
    {
        throw domain_error( "Your domain is in error!" );
    }

}
int largo(long int i)
{
    int n=0;
    while (i) {
        i /= 10;
        n++;
    }
    return n;
}
string MFD::toString(){
    string a,b,c,d,r;
    b=to_string(entero);
    c=to_string(fraccion);
    d=to_string(exponente);
     if(signo)
    {
        r=b+"."+c+"E"+d;
    }
    else{
        a="-";
        r=a+b+"."+c+"E"+d;
    }
    return r;
}
MFD MFD:: operator * (MFD mfd)
{
    MFD aux(0,0,0,0);
    vector<long int> v1,v2,v3;
    bool s=signo,_s=mfd.signo,aux_s;
    long int e=entero,_e=mfd.entero,aux_e;
    long int f=fraccion,_f=mfd.fraccion,aux_f;
    long int exp=exponente,_exp=mfd.exponente,aux_exp;


    aux_s= s && _s;
    //v1 contiene un vector con el entero y parte fraccionara del primer numero a multiplicar
    while (f!=0)
        {
            long int r=f%10;
            v1.push_back(r);
            f /= 10;
        }
     while (e!=0)
        {
            long int r=e%10;
            v1.push_back(r);
            e /= 10;
        }
    //v2 contiene un vector con el entero y parte fraccionara del segundo numero a multiplicar
        while (_f!=0)
        {
            long int r=_f%10;
            v2.push_back(r);
            _f /= 10;
        }
     while (_e!=0)
        {
            long int r=e%10;
            v2.push_back(r);
            _e /= 10;
        }
    //largo de la parte decimal, asi sabremos donde poner la coma
    long int largo_decimal=largo(f)+largo(_f);
    vector<long int>::iterator it1=v1.end();
    vector<long int>::iterator it2=v2.end();
    //multiplicacion de ambos vectores almacenados en v3
    while(it1!=v1.begin())
    {
        while(it2!=v2.begin())
        {
            long int t=(*it1)*(*it2);
            if(t<10)
            {
                v3.push_back(t);
            }
            else
            {
                v3.push_back(t%10);
                v3.push_back(t/10);
            }
            it2--;
        }
        it1--;
    }
    vector<long int>::iterator it3=v3.begin();
    //En este iterador tenemos marcado donde va el punto decimal (o la coma)
    vector<long int>::iterator punto_decimal=v3.end()-largo_decimal;
    //Solo queremos un numero como entero, el resto estará en las fracciones
    aux_e=(*it3);
    //Definimos 5 espacios para el largo de la fraccion
    int n=5;
    for(int i=1;i<=5;i++)
    {

        //aqui tomamos del segundo elemento de v3 hasta el 6to elemento y los sumamos, no olvidando las potencias de 10
        aux_f=aux_f+(*(it3+i))*pow(10,n);
        n--;
    }
    //contamos cuantos espacios hay desde el segundo puesto hasta la coma decimal, para saber cuanto sumar al exponente
    int cont=0;
    while(it3!=punto_decimal)
    {
        it3++;
        cont++;
    }
    aux_exp=exp+_exp+cont++;


    aux.setSigno(aux_s);
    aux.setEntero(aux_e);
    aux.setFraccion(aux_f);
    aux.setPotencia(aux_exp);

    return aux;

}

int main()
{
    MFD m(true,3,14159,0);
    m.imprime();

    return 0;
}


