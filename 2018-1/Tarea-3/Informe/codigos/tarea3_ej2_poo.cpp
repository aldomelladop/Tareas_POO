#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>


using namespace std;
string minuscula(string a)
{
     a[0]=tolower(a[0]);
     return a;
}
string mayuscula(string a)
{
     a[0]=toupper(a[0]);
     return a;
}
int main()
{

    ifstream apellidos_US("Apellidos_US.txt");
    ifstream hombres_US("NombresHombres.txt");
    ifstream mujeres_US("NombresMujeres.txt");
    string temp;
    vector<string> apellidos;
    vector<string> hombres;
    vector<string> mujeres;
    //Se escriben en minusculas para luego poder hacer las permutaciones sin problemas en el
    //uso de caracteres
    while(apellidos_US >> temp)
        {
            temp=minuscula(temp);
            apellidos.push_back(temp);
        }
    while(hombres_US >> temp)
        {
            temp=minuscula(temp);
            hombres.push_back(temp);
        }
    while(mujeres_US >> temp)
        {
            temp=minuscula(temp);
            mujeres.push_back(temp);
        }

    string nombre, apellido, sexo;
    cout << "Ingrese el nombre a buscar: ";
    cin >> nombre;
    nombre=minuscula(nombre);
    cout << "Ingrese el apellido a buscar: ";
    cin >> apellido;
    apellido=minuscula(apellido);
    cout << "Ingrese el sexo (M/F): ";
    cin >> sexo;
    sexo=minuscula(sexo);
    //Se agregan estas lineas en caso que la persona no siga las instrucciones
    //y escriba el sexo en una palabra
    if(sexo=="masculino"){sexo="m";}
    if(sexo=="femenino"){sexo="f";}
    // Se crea un string concatenando nombre y apellido para poder econtrar las permutaciones
    // ademas se agrega un caracter especial "_", el cual va a servir para poder separar todas
    // las permutaciones posibles en dos, una parte siendo el nombre, y la otra el apellido.
    string nom_ap;
    nom_ap=nombre+apellido;
    //Se ordena este string en orden alfabetico, de esa forma se garantiza que se encuentren
    // todas las permutaciones
    sort(nom_ap.begin(),nom_ap.end());

    //vector<pair<string,string>> respuesta;
    //vector<pair<string,string>>::iterator it_respuesta=respuesta.begin();

    vector<string> respuesta;

    vector<string>::iterator ap=apellidos.begin();
    vector<string>::iterator ho=hombres.begin();
    vector<string>::iterator mu=mujeres.begin();
    //Se ponen las condiciones para saber si buscar en la lista de mujeres o de hombres
    //Se utiliza la funsion is_permutation para encontrar las permutaciones posibles, y ademas
    //se pone la condicion de que tiene que ser del mismo largo que la suma de los caracteres de
    //la palabra original.
    if(sexo=="m")
    {
    while(ho!=hombres.end())
    {
        ap=apellidos.begin();
        while(ap!=apellidos.end())
        {
            auto aux=(*ho)+(*ap);
            if(is_permutation(nom_ap.begin(),nom_ap.end(),aux.begin())&& aux.size()==nom_ap.size())
            {
                string resultado=mayuscula(*ho)+" "+mayuscula(*ap);
                respuesta.push_back(resultado);
            }
          ap++;
        }
        ho++;
    }
    }
    if(sexo=="f")
    {
    while(mu!=mujeres.end())
    {
        ap=apellidos.begin();
        while(ap!=apellidos.end())
        {
            auto aux=(*mu)+(*ap);
            if(is_permutation(nom_ap.begin(),nom_ap.end(),aux.begin())&& aux.size()==nom_ap.size())
            {
                string resultado=mayuscula(*mu)+" "+mayuscula(*ap);
                respuesta.push_back(resultado);
            }
          ap++;
        }
        mu++;
    }
    }

    cout<<"A continuacion, los posibles alias generados a partir del nombre son:"<<endl;
   for(auto x:respuesta){cout<<x<<endl;}

    return 0;
}

