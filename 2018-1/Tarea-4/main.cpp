#include <iostream>
#include <ostream>
#include <string>
#include <numeric>
#include <algorithm>
#include <istream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <sstream>
using namespace std;


class MFD {

    //declaraciones
private:
    bool signo;
    long int entero;
    long int fraccion;
    long int exponente;

    MFD normalizar(MFD mfd);
    pair<long int, long int> normalizar(double var)
    {
        long int exp = 0;
        if(var == 0) return make_pair(0,0);
        while(var < 0.1)
        {
            exp--;
            var *= 10;
        }
        var *= 1000000000;
        return make_pair(var, exp);
    }

public:
    //constructor
    MFD(bool,long int,long int,long int);
    MFD(long int);
    MFD(double);
    MFD(const MFD &mfd);

    double toDouble() const;

    string toString();

    bool getSigno() const;
    long int getEntero() const;
    long int getFraccion() const;
    long int getExponente() const;

    void setSigno(bool);
    void setEntero(long int);
    void setFraccion(long int);
    void setExponente(long int);
    void imprime();


    MFD& operator += (const MFD &mfd );
    MFD& operator -= (const MFD &mfd );
    MFD& operator *= (const MFD &mfd );
    MFD& operator /= (const MFD &mfd );

    bool operator == (const MFD &mfd )const;
    bool operator != (const MFD &mfd )const;

    MFD& operator = (const MFD &mfd );
 //operadores de sobrecarga
    friend ostream& operator<< (ostream &salida, const MFD &mfd);
    friend istream& operator>>(istream &entrada, MFD &mfd);




   };

   MFD::MFD(bool s,long int ent,long int frac,long int exp){
        signo = s; // solo toma valores 1-0
        entero = ent; //parte entera
        fraccion = frac; // parte fraccional
        exponente = exp; // base 10
    }
MFD ::MFD(const MFD &numero)
{
    *this=numero;

}
    MFD::MFD(long int numero)
    {
        if (numero<0){signo=false;} else{signo=true;}
        entero=(numero>=0)? numero:numero*-1;
        fraccion=0;
        exponente=0;
    }
    MFD::MFD(double numero)
    {
        if (numero<0){signo=false;} else{signo=true;}
        numero=(numero>=0)? numero:numero*-1;
        entero=(long int) numero;


        pair<long int,long int> norma=normalizar(numero - entero);

        fraccion=norma.first;
        exponente=norma.second;

        while(fraccion%10==0 && fraccion!=0)
        {
            fraccion/=10;
        }

        for(int i=exponente;i<0;i++)
        {
            entero*=10;
        }


    }


    //funciones get y set correspondientes
    bool MFD::getSigno() const{
        return signo;
    }
    void MFD::setSigno(const bool st){
        signo=st;
    }

    long int MFD::getEntero() const{
        return entero;
    }
    void MFD::setEntero(long int entt){
    entero=entt;
    }

    long int MFD::getFraccion() const{
    return fraccion;
    }
    void MFD::setFraccion(long int fract){
    fraccion= fract;
    }

    long int MFD::getExponente() const{
    return exponente;
    }
    void MFD::setExponente(long int expt)
    {
    exponente=expt;
    }

    void MFD::imprime(){
              if(signo==0){
                  cout<<"Numero es: "<<"-"<<" ("<<entero<<"."<<fraccion<<") 10^("<<exponente<<")"<<endl;
                }
               if(signo!=0){

                    cout<<"Numero es: "<<"+"<<" ("<<entero<<"."<<fraccion<<") 10^("<<exponente<<")"<<endl;
                    }

    }
    //operaciones basi

    MFD& operator+(const MFD &numero1,const MFD &numero2)
    {
        double Dnumero1=numero1.toDouble();
        double Dnumero2=numero2.toDouble();
        return *(new MFD( Dnumero1+Dnumero2));
        }

  // /*   void operator+=(const MFD &numero1,const MFD &numero2)
   MFD& MFD::operator+=(const MFD &numero)
    {
        double DnumeroR=this->toDouble()+ numero.toDouble();
        MFD tem(DnumeroR);
        this->setSigno(tem.getSigno());
        this->setEntero(tem.getEntero());
        this->setFraccion(tem.getFraccion());
        this->setExponente(tem.getExponente());
        return *this;
    }
//*/
      MFD& operator -(const MFD &numero1,const MFD &numero2)
    {
        double Dnumero1= numero1.toDouble();
        double Dnumero2= numero2.toDouble();
        return *(new MFD(Dnumero1-Dnumero2));

    }
 //* void operator-=(const MFD &numero1,const MFD &numero2)
  MFD& MFD::operator-=(const  MFD &numero)
    {

        double DnumeroR=this->toDouble()- numero.toDouble();
        MFD tem(DnumeroR);
        this->setSigno(tem.getSigno());
        this->setEntero(tem.getEntero());
        this->setFraccion(tem.getFraccion());
        this->setExponente(tem.getExponente());
        return *this;

        }
//*/

        MFD& operator*(const MFD &numero1,const MFD &numero2)
    {
        double Dnumero1= numero1.toDouble();
        double Dnumero2= numero2.toDouble();
        return *(new MFD(Dnumero1*Dnumero2));

        }

//*void operator*=(const MFD &numero1,const MFD &numero2)
        MFD& MFD::operator*=(const MFD &numero)
    {
        double DnumeroR=this->toDouble() * numero.toDouble();
        MFD tem(DnumeroR);
        this->setSigno(tem.getSigno());
        this->setEntero(tem.getEntero());
        this->setFraccion(tem.getFraccion());
        this->setExponente(tem.getExponente());
        return *this;


    }
//*/
        MFD& operator/(const MFD &numero1, const MFD &numero2)
        {
            double Dnumero1= numero1.toDouble();
            double Dnumero2= numero2.toDouble();
            if(Dnumero2==0)throw domain_error("denominador 0");
            return *(new MFD(Dnumero1/Dnumero2));

        }

    //void operator/=(const MFD &numero1,const MFD &numero2)
     MFD& MFD::operator/=( const MFD &numero)
    {
        double DnumeroR=this->toDouble() / numero.toDouble();
        MFD tem(DnumeroR);
        this->setSigno(tem.getSigno());
        this->setEntero(tem.getEntero());
        this->setFraccion(tem.getFraccion());
        this->setExponente(tem.getExponente());
        return *this;

    }

MFD& MFD::operator=(const MFD &numero)
{

        this->setSigno(numero.getSigno());
        this->setEntero(numero.getEntero());
        this->setFraccion(numero.getFraccion());
        this->setExponente(numero.getExponente());
        return *this;
}


bool MFD::operator == (const MFD &numero)const
{
  if(this-> getSigno()==numero.getSigno()&& this-> getEntero()==numero.getEntero()&& this-> getFraccion()==numero.getFraccion()&&this-> getExponente()==numero.getExponente())  {
    cout << "iguales" << endl;
  }
  else{cout << "no son iguales" << endl;}
}

bool MFD::operator!=(const MFD &numero) const
{
      if(this-> getSigno()!=numero.getSigno() || this-> getEntero()!=numero.getEntero() || this-> getFraccion()!=numero.getFraccion() || this-> getExponente()!=numero.getExponente()) {
      cout << "iguales" << endl;
  }
  else{
        cout << "no son iguales" << endl;
  }
}

ostream& operator << (ostream &salida, const MFD &numero)
{
if(numero.getSigno()==1)
{
        salida<<"(true,"<<numero.getEntero()<<","<<numero.getFraccion()<<","<<numero.getExponente()<<")";
        return salida;

}
if(numero.getSigno()!=1)
{
        salida<<"(false,"<<numero.getEntero()<<","<<numero.getFraccion()<<","<<numero.getExponente()<<")";
        return salida;
}

}
istream& operator >> (istream &entrada, MFD &numero)
{
            bool s;
            long int ent;
            long int frac;
            long int exp;
            char p;
            entrada>>s>>p>>ent>>p>>frac>>p>>exp;
            if(ent>=0)
            {
                s=true;
            }
            else%10
            {
                s=false;
                ent*=(-1);
            }

            numero.setEntero(ent);
            numero.setExponente(exp);
            numero.setFraccion(frac);
            numero.setSigno(s);
            entrada.ignore();
            return entrada;

}

 double MFD::toDouble() const
    {
        if(exponente > 308 || exponente < -308) throw domain_error( "El numero no cabe en el double" );
        double to_ret = entero;
        double temp = (double) fraccion;

        while(temp >= 1)
            temp = temp /10;

        to_ret += temp;
        to_ret *= pow(10, exponente);
        if(signo)
            return to_ret;
        else
            return to_ret * (-1);
    }

string MFD::toString()
    {
        ostringstream ss;
        ss << "("<<(signo ? "": "-") <<entero << "," << fraccion << "," << exponente<<")";
        return ss.str();
    }




int main()
{

    double PI=3.14159265359;
    double numero=1.0203;

    MFD PI2(true,3,14159265359,1000);

    //MFD Caso0(0);
    MFD Caso1=MFD(3.14159265359);
    MFD Caso2=MFD(-3.14159265359);

    MFD ejemplo1(true,15,0,-2);
    MFD ejemplo2(false,12,909,-1);
    MFD ejemplo3(true,32,0,-1);

    cout<<" Funcion Imprimir : "<<endl;
    cout<<"numero ejemplo1";
    ejemplo1.imprime();
    cout<<"numero ejemplo2";
    ejemplo2.imprime();
    cout<<"numero ejemplo3";
    ejemplo3.imprime();

    cout<<endl;
    cout<<"caso de sobrecarga de operadores"<<endl;
    cout<<"caso ejemplo1= ";
     ejemplo1.imprime();
     cout <<"  = "<<ejemplo1.toDouble();

     cout<<endl;

    cout<<"caso ejemplo2= ";
     ejemplo2.imprime();
     cout <<" = "<<ejemplo2.toDouble();
    cout<<endl;

    cout<<"caso ejemplo3= ";
    ejemplo3.imprime();
    cout<<" = "<<ejemplo3.toDouble();
    cout<<endl;

    cout<<"caso ejemplo1!=ejemplo2 ";
    ejemplo1!=ejemplo2;

    cout<<"caso ejemplo1==ejemplo3 ";
    ejemplo1==ejemplo3;
    cout<<endl;

    cout<<"caso de las operaciones"<<endl;
    cout<<"ejemplo1+ejemplo2 = "<< ejemplo1+ejemplo2<<" = "<<ejemplo1.toDouble()+ejemplo2.toDouble()<<endl;
    cout<<"ejemplo1-ejemplo2 = "<< ejemplo1-ejemplo2<<" = "<<ejemplo1.toDouble()-ejemplo2.toDouble()<<endl;
    cout<<"ejemplo1*ejemplo2 = "<< ejemplo1*ejemplo2<<" = "<<ejemplo1.toDouble()*ejemplo2.toDouble()<<endl;
    cout<<"ejemplo1/ejemplo2 = "<< ejemplo1/ejemplo2<<" = "<<ejemplo1.toDouble()/ejemplo2.toDouble()<<endl;

    cout<<endl;
    cout<<"Caso de PI:"<<endl;
    cout<<"PI:"<< PI<<endl;
    cout<<"PI elevado a 1000: "<< PI2<<" ="<<endl;

    double calculoP=pow(PI,1000);

    if(calculoP>=2.23e308){cout<<"El numero no cabe en el double"<<endl;}
    else {cout<<calculoP<<endl;}


    return 0;
}
