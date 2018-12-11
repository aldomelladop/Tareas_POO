#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

/*---------------------------- Ejemplo hypotenusa---------------------------*/

/*
int hypotenuse(int a, int b)
{
int c;

c = pow((pow(a,2) + pow(b,2)),0.5);

return c;
}

int main()
{
    int cat1, cat2, hyp;

    cout<<"Introduzca el valor de los catetos: "; cin>>cat1>>cat2;

    cout<<"el valor de la hipotenusa es: "<<hypotenuse(cat1,cat2)<<endl;
}
*/

/*---------------------------- Ejemplo función ----------------------------*/

/*
float fequisye(int a, int b)
{
float num,den,res;

num =  pow(a,0.5);
den = pow(b,2)-1;
res = num/den;

return res;
}

int main()
{
int x,y;

cout<< "Ingrese los valores de x e y: "; cin>>x>>y;

cout<<"La función evaluada en los valores de x e y es: "<<fequisye(x,y);
}
*/

/*---------------------------- Ejemplo ecquad----------------------------*/

/*
pair <float,float> sol(int x, int y, int z)
{
pair<float,float> m;

float det,num1,num2,den,sol1,sol2;

det = pow((pow(y,2)- 4*x*z),0.5);
num1 = -y - det;
num2 = -y + det;
den = 2*x;

cout<<"determinante "<<det<<endl;
cout<<"denominador "<<den<<endl;
cout<<"numerador - "<<num1<<endl;
cout<<"numerador + "<<num2<<endl;
cout<<endl;

sol1 = num1/den;
sol2= num2/den;

m.first = sol1;
m.second= sol2;

return m;
}


int main()
{

int a,b,c;

cout<<endl;
cout<<"Ingrese los valores de los coeficientes que acompañan a los términos de x, es decir, ingrese A, B, C: ";cin>>a>>b>>c;

pair<float,float> n;
n= sol(a,b,c);

cout<<"las soluciones para la ecuación con coeficientes: "<<a<<"x^2 +"<<b<<"x + "<<c<<" son: "<<setprecision(2)<< n.first<<" , "<<n.second<<endl;

return 0;
}
*/

/*---------------------------------- Ejemplo Switch ------------------------*/

/*
 int main()
 {
 	int numero;
 	cout<<" Ingrese un número del 1 al 5: ";cin>>numero;cout<<endl;

 	switch(numero)
 	{	case 1: cout<<"el número ingresado es 1"<<endl;break;
 		case 2: cout<<"el número ingresado es 2"<<endl;break;
        case 3 : cout<<"el número ingresado es 3 "<<endl;break;
        case 4: cout<<"El número ingresado es 4 "<<endl;break;
        case 5: cout<<"El número ingresado es 5 "<<endl;break;
        default: cout<<"el numero ingresado es distinto al requerido"<<endl;break;
    }

 return 0;
 }
*/

/*---------------------------------- Ejemplo if ------------------------*/

/*
int main()
{

string palabra;

cout<<"Ingrese una palabra: "; cin>>palabra;

cout<<" A mi me gusta el tangananica"<<endl;
cout<<" Y yo prefiero el "<<endl;

if(palabra=="tangananica")
    {
    cout<<"la palabra escrita es: "<<palabra<<endl;
    }
else
    {
    cout<<"la mejor palabra es tangananá"<<endl;
    }
return 0;
}
*/

/*---------------------------------- Ejemplo  if-else ------------------------*/

//int main()
//{
//    int numero;
//
//    cout<<" Ingrese el número a evaluar: ";
//    cin>>numero;
//
//    if(numero == 0)
//        {
//        cout<<" El número es cero"<<endl;
//        }
//    else
//        {
//         if(numero<0 && numero!=0)
//         {
//            cout<<" El número es negativo"<<endl;
//         }
//        else
//        {
//        cout<<" El número es positivo"<<endl;
//        }
//        }
//    return 0;
//}

/*---------------------------------- Ejemplo for------------------------*/

//int main()
//{
//	int i,l;
//
//	string nombre;
//	cout<<"ingrese su nombre: ";
//	cin>>nombre;
//
//	l = nombre.size();
//
//	for(i=0;i<l;i++)
//	{
//        if(i<l-1)
//        {
//		cout<<nombre[i]<<endl;
//		}
//		else
//		cout<<nombre[i];
//    }
//return 0;
//}

/*---------------------------------- Ejemplo Cajero ------------------------*/

//int main ()
//{
//int saldo_i= 1000;
//int monto, deposito,op;
//string opcion;
//
//cout<<"\t Bievenido a su cajero virtual"<<endl;
//cout<<"\t Ingrese la operación que desea realizar: "; cin>>opcion;
//
//switch(opcion)
//{
//    case 'depositar': {cout<<"ingrese el monto a depositar"<<endl;cin>>monto; deposito = saldo_i+monto;
//                        cout<<" Saldo final es: "<<deposito;};break;
//    case 'otro': cout<<"so sorry, not developed yet"<<endl;break;
//    default: cout<<"bye"<<endl;break;
//}
//return 0;
//}

/*Revisar*/

/*---------------------------------- Ejemplo tabla de multiplicar  ------------------------*/


//int main()
//{
//	int numero;
//
//	do{
//		cout<<" Digite un número del 1 al 10"<<endl;cin>>numero;
//	}
//
//	while(numero<1 || numero>10);
//	for (int i = 0; i <13; ++i)
//	{
//		cout<<numero<<" * "<<i<<" = "<< numero*i<<endl;
//	}
//	return 0;
//}

/*---------------------------------- Ejemplo cuadrados<10  ------------------------*/

//int main()
//{
//	int numero,suma;
//
//	do
//	{
//		cout<<" Ingrese un número mayor que cero: "<<endl;cin>>numero;
//	}
//	while(numero<0  || numero>10);
//
//	for(int i=0;i<11;i++)
//	{
//		suma= suma + pow(i,2);
//	}
//
//	cout<<"la suma de los 10 primeros números mayores que cero es: "<<suma<<endl;
//
//	return 0;
//}

/*---------------------------------- Ejemplo suma hasta  ------------------------*/

// int main()
// {
// 	int op=0;
// 	do{

// 	int suma=0, n;

// 	cout<<" Indique el número hasta el cual desea que se realice la suma: ";cin>>n;
// 	for(int i=0;i<=n;i++)
// 		{
// 			suma=suma+i;
// 		}

// 	cout<<"El valor de la suma hasta el termino "<<n<<" es: "<<suma<<endl;

// 	cout<<"Si desea realizar otra operación, ingrese 1, en caso contrario, ingrese cero: ";cin>>op;
// 	}
// 	while(op==1);

// 	return 0;

// }

/*---------------------------------- Ejemplo factorial ------------------------*/

/*
int main()
{
	int op=0;
	do
	{
	int n;
	long double factorial=1;

	cout<<" Ingrese el número del cual desea obtener el factorial: ";cin>>n;cout<<endl;

	for(int i=1;i<=n;i++)
	{

		factorial=factorial*i;
	}

	cout<<"El resultado del factorial de "<<n<<" es "<<factorial<<endl;
	cout<<"Si desea calcular el factorial de otro número, ingrese la opción 1, en caso contrario, escriba 0: ";cin>>op;
	}
	while(op==1);

	return 0;
}
*/

/*---------------------------------- Ejemplo suma factorial ------------------------*/

//int main()
//{
//	int op=0;
//	do
//	{
//	int n;
//	long double factorial=1,suma=0;
//
//	cout<<" Ingrese el número del cual desea obtener el factorial: ";cin>>n;cout<<endl;
//
//	for(int i=1;i<=n;i++)
//	{
//		factorial=factorial*i;
//		suma = suma + factorial;
//	}
//
//	cout<<"El resultado del factorial de "<<n<<" es "<<factorial<<endl;
//	cout<<"El resultado de la suma de los factoriales de "<<n<< " es "<<suma<<endl;
//	cout<<"Si desea calcular el factorial de otro número, ingrese la opción 1, en caso contrario, escriba 0: ";cin>>op;
//	}
//
//	while(op==1);
//
//	return 0;
//}

/*--------------------------------- ejemplo suma potencias base 2 --------------------------------------*/

// int main()
// {
// 	int n, power=0;

// 	cout<<"Ingrese el valor de cual desea obtener la suma de potencias de 2: ";cin>>n;


// 	for(int i=0;i<=n;i++)
// 	{
// 		power = power + pow(2,i);
// 	}

// 	cout<<" El resultado de la suma es: "<<power<<endl;

//     return 0;
// }

/*--------------------------------- ejemplo fibonacci --------------------------------------*/

/* int main()
{
 	int fibonacci=0,n,j=0;
	cout<<"Ingrese el número de la secuencia que desea imprimir: ";cin>>n;
	cout<<"los números de la secuencia de fibonacci son: 1";
	for(int i=1;i<=n;i++)
	{
 		fibonacci = fibonacci + i + j;
 		cout<<" "<<fibonacci;
     j = 1 ;
 	}
	return 0;
 }
*/

/*
int main()
{
	int n, x=0,y=1;
	long double z=1;

	cout<<"Digite el número de elementos: ";cin>>n;

	cout<<" 1 ";

	for(int i=1;i<n;i++)
	{
		z = x + y;
		cout<<z<<" ";
		x = y;
		y = z;
	}

}
*/

/*--------------------------------- ejemplo Vectores e iteradores --------------------------------------*/
						/*----------------- Pendiente -----------------*/

//int main()
//{
//	int n;
//	vector<int> numeros;
//	vector<int> mult,productoria;
//
//	cout<<"ingrese un número ";cin>>n;
//
//	int n_size;
//	n_size= numeros.size();
//
//	cout<<" números es un vector de tamaño "<<n_size<<endl;
//
//	cout<<"La multiplicación acumulada de los elementos de número es ";
//
//	for(int i=0;i<n_size;i++)
//	 {
//	 	//cout<<i<<endl;
//	 	productoria[i]= productoria[i]*mult[i];
//	 	cout<<productoria[i]<<endl;
//	}
//	return 0;
//}

/*--------------------------------- ejemplo Vectores --------------------------------------*/

/*1, Hacer un programa para rellenar una matri pidiendo al usuario el número de filas y columnas, posteriormente, mostrar la matriz en pantalla.*/

// int main()
// {
// 	int numeros[100][100], filas, columnas;

// 	cout<<" Digite el número de filas: ";cin>>filas;
// 	cout<<" Digite el número de columnas: ";cin>>columnas;

// 	for(int i=0;i<filas;i++)
// 		{
// 			for(int j=0;j<columnas;j++)
// 			{
// 				cout<<"Digite un número a ingresar a la columna:  ["<<i<<"]"<<"["<<j<<"] ";
// 				cin>>numeros[i][j];
// 			}

// 		}

// 	for(int i=0;i<filas;i++)
// 		{
// 			for(int j=0;j<columnas;j++)
// 			{
// 			cout<<numeros[i][j];
// 			}
// 		cout<<endl;
// 		}

// 	return 0;
// }

/*---------------------------------------------- Diagonal matriz ----------------------------*/

/*
int main()
{
	int numeros[100][100], filas, columnas;

	cout<<" Digite el número de filas: ";cin>>filas;
	cout<<" Digite el número de columnas: ";cin>>columnas;

	int diag[columnas];

	for(int i=0;i<filas;i++)
		{
			for(int j=0;j<columnas;j++)
			{
				cout<<"Digite un número a ingresar a la columna:  ["<<i<<"]"<<"["<<j<<"] ";
				cin>>numeros[i][j];
			}

		}
	int k=0,b=0;

	for(int i=0;i<filas;i++)
		{
			for(int j=0;j<columnas;j++)
			{
			cout<<numeros[i][j];
			}
		cout<<endl;
		}

	//Diagonal de matriz

		cout<<"La diagonal de la matriz es: ";
		for(int i=0;i<filas;i++)
		{
			for(int j=0;j<columnas;j++)
			{
				if (i==j)
				{
				cout<<numeros[i][j];
				}
			}
		}
	return 0;
}
*/

/*---------------------------------------------- Matriz Traspuesta ----------------------------*/

/*
int main()
{
 	int numeros[100][100], filas, columnas;
	cout<<" Digite el número de filas: ";cin>>filas;
  	cout<<" Digite el número de columnas: ";cin>>columnas;
  	int traspuesta[100][100];
 	for(int i=0;i<filas;i++)
  		{
  			for(int j=0;j<columnas;j++)
  			{
  				cout<<"Digite un número a ingresar a la columna:  ["<<i<<"]"<<"["<<j<<"] ";
  				cin>>numeros[i][j];
  			}
  		}
  	for(int i=0;i<filas;i++)
  		{
  			for(int j=0;j<columnas;j++)
  			{
  			cout<<numeros[i][j];
  			}
  		cout<<endl;
  		}
 	cout<<"\nMatriz Traspuesta "<<endl;
 	 	for(int i=0;i<filas;i++)
  		{
  			for(int j=0;j<columnas;j++)
  			{
  			cout<<numeros[j][i];
  			}
  		cout<<endl;
  		}
	return 0;
 }
*/

/*---------------------------------------------- Matriz simétrica ----------------------------*/

/*int main()

{
	int numeros[100][100], filas, columnas;

	cout<<" Digite el número de filas: ";cin>>filas;
 	cout<<" Digite el número de columnas: ";cin>>columnas;
 	int traspuesta[100][100];

 	for(int i=0;i<filas;i++)
 		{
 			for(int j=0;j<columnas;j++)
 			{
 				cout<<"Digite un número a ingresar a la columna:  ["<<i<<"]"<<"["<<j<<"] ";
 				cin>>numeros[i][j];
 			}
 		}

 	for(int i=0;i<filas;i++)
 		{
 			for(int j=0;j<columnas;j++)
 			{
 			cout<<numeros[i][j];
 			}
 		cout<<endl;
 		}

 	cout<<"\nMatriz Traspuesta "<<endl;

 	 	for(int i=0;i<columnas;i++)
 		{
 			for(int j=0;j<filas;j++)
 			{
 			cout<<numeros[j][i];
 			}
 		cout<<endl;
 		}

 	cout<<"\nComprobación de simetría"<<endl;
 	char band='F';

 	if(filas==columnas)
 	{
		for(int i=0;i<filas;i++)
 		{
 			for(int j=0;j<columnas;j++)
 			{
 			if (numeros[i][j]==numeros[j][i])
 			{
 				band='V';
 			}
 			}
 		}
 	}

 	if(band=='V')
 	{
 		cout<<"\nLa matriz es simétrica";
 	}
 	else
 	{
 		cout<<"\nLa matriz no es simétrica";
 	}
	return 0;
}
*/
/*---------------------------------------------- strings  ----------------------------*/

//int main()
//{
//	char palabra[] = "alejandro";
//	char palabras[] = {'a','l','e','j','a','n','d','r','o'};
//
//	cout<<"palabra[] "<<palabra<<endl;
//	cout<<"\npalabras[] "<<palabras<<endl;
//	return 0;
//}

/*--------------------------------- Suma elementos de un vector y cambiar signo ------------------------------------*/
					/*------------------------ Ejemplo Iteradores --------------------------*/
/*
vector<int> vec,opp; int tam;

vector<int> cambiodesigno(vector<int> vec)
{
    vector<int> opp;
    vector<int>::iterator it=vec.begin();
    vector<int>::iterator itp=opp.begin();

    for(it;it<vec.end();it++)
    {
        *it *= -1;
        opp.push_back(*it);
    }

    return opp;
}

int calcularSuma(vector<int> vecto)
{
    vector<int>::iterator it1=vecto.begin();

    int Suma=0;
    for(it1; it1<vecto.end(); it1++)
    {
        Suma = Suma + (*it1);
    }
    return Suma;
}

void imprimevector(vector<int> vect)
{
	vector<int>::iterator iti=vect.begin();
	cout<<"[";
	for(iti;iti<vect.end();iti++)
	{
		cout<<*iti<<" ";
		if(iti==vect.end()-1)
		{
			cout<<"]";
		}
	}
}

void pedirDatos()
{
	int n;
	cout<< "Digite el número de elementos del vector "<<endl;
	cin>>tam;

	for(int i=0;i<tam;i++)
	{
		cout<<i+1<<". Digite el número: ";
		cin>>n;
		vec.push_back(n);
		//it++;
	}
}

int main()
{
	vector<int> op;

	pedirDatos();

	//cambiodesigno(vec);
	//imprimevector(op);

	cout<<"\nLa suma de los datos del vector es: "<<calcularSuma(vec)<<endl;
	cout<<"\nLos elementos del vector con signo cambiado son: "; imprimevector(cambiodesigno(vec));

 return 0;
}
*/

/*---------------------------------- Elementos de matriz al cuadrad---------------------------*/

/*void constimprmatriz(int filas, int columnas)
{
	int numeros[100][100];

	for(int i=0;i<filas;i++)
  		{
  			for(int j=0;j<columnas;j++)
  			{
  				cout<<"Digite un número a ingresar a la columna:  ["<<i<<"]"<<"["<<j<<"] ";
  				cin>>numeros[i][j];
  			}
  		}
  	cout<<endl;

  	{
	for(int i=0;i<filas;i++)
	  		{
	  			for(int j=0;j<columnas;j++)
	  			{
	  			cout<<pow(numeros[i][j],2);
	  			}
	  		cout<<endl;
	  		}
	}
}


int main()
{
 	int numeros[100][100], filas, columnas;
	cout<<" Digite el número de filas: ";cin>>filas;
  	cout<<" Digite el número de columnas: ";cin>>columnas;

 	constimprmatriz(filas,columnas);

 	return 0;
 }
*/

/*----------------------------------  strupr()  ---------------------------*/

/*vector<char> palabra;

void palabraaminuscula(vector<char> palabra)
{

}

int main()
{

	cout<<"Ingrese una palabra en minúsculas"<<endl;
	getline(cin,palabra);
	cout<<palabra;

	palabraaminuscula(palabra);
	return 0;
}
*/

/*----------------------------------  atoi() atof()  ---------------------------*/

/*
int main()
{
	char num[10],numf[10];

	int numero;
	float numerof;

	cout<<"ingrese un número entero: ";
	cin>>num;

	numero = atoi(num);

	cout<<"El número ingresado al cuadrado coresponde a: "<<pow(numero,2)<<endl;


	cout<<"\nIngrese un número decimal: ";
	cin>>numf;

	numerof = atof(numf);

	cout<<"El número ingresado al cuadrado coresponde a: "<<pow(numerof,2)<<endl;
	return 0;
}*/

/*----------------------------------   contador de ocurrencias ---------------------------*/

/*vector<char> palabra,vec;

void contadorocurrencias(vector<char> palabra)
{
	vector<char>::iterator it =palabra.begin();
	int ca=0,ce=0,co=0,ci=0,cu=0;

	for(it;it<palabra.end();it++)
	{
		switch(*it)
		{
			case 'a':ca++;break;
			case 'e':ce++;break;
			case 'i':ci++;break;
			case 'o':co++;break;
			case 'u':cu++;break;
		}
	}
	cout<<endl;
	cout<<"\nLa cantidad de letras a es: "<<ca<<endl;
	cout<<"La cantidad de letras e es: "<<ce<<endl;
	cout<<"La cantidad de letras i es: "<<ci<<endl;
	cout<<"La cantidad de letras o es: "<<co<<endl;
	cout<<"La cantidad de letras u es: "<<cu<<endl;
}

void imprimevector(vector<char> palabra)
{
	vector<char>::iterator iti=palabra.begin();

	cout<<"[";
	for(iti;iti<palabra.end();iti++)
	{
		cout<<*iti<<" ";
		if(iti==palabra.end()-1)
		{
			cout<<"]";
		}
	}
}

void pedirDatos()
{
	int largo;
	string word;
	cout<<"Ingrese una palabra: ";
	cin>>word;

	string::iterator it=word.begin();
	largo = word.size();

	for(int i=0;i<largo;i++)
	{
		palabra.push_back(*it);
		it++;
	}
}

int main()
{
	pedirDatos();
	imprimevector(palabra);
	contadorocurrencias(palabra);
}
*/

/*---------------------------------- Ordenamiento burbuja  ---------------------------*/
/*
vector<int> numero,numord;

void imprimevector(vector<int> numero)
{
	cout<<"[";
	vector<int>::iterator it=numero.begin();

	for(it;it<numero.end();it++)
	{
		cout<<*it<<" ";
		if(it==numero.end()-1)
		{
			cout<<"]";
		}
	}
}

void pedirDatos()
{
	int n=0,tam=0;
	cout<< "Digite la cantidad de dígitos del vector: ";
	cin>>tam;

	for(int i=0;i<tam;i++)
	{
		cout<<"Digite el " << i+1 << "° número: ";
		cin>>n;
		numero.push_back(n);
		//it++;
	}
}

void ordenavector(vector<int> numero)
{	

	sort(numero.begin(),numero.end());

	cout<<"\nLos elementos del vector ordenados son: ";
	imprimevector(numero);
}

int main()
{
    pedirDatos();
    imprimevector(numero);
    ordenavector(numero);
    return 0;
}
*/

/*----------------------------------------- Plantilla de función ---------------------------------*/

/*
template <class TIPOD>
void despliegue(TIPOD dato)
{
	cout<<"el valor del dato ingresado es: "<<dato<<endl;
}

int main()
{
	char dato  	= 'S';
	int dato2 	= 3;
	float dato3	= 142.13;
	double dato4=43.23123;

	despliegue(dato);
	despliegue(dato2);
	despliegue(dato3);
	despliegue(dato4);


	return 0;
}
*/

/*----------------------------------------- Piramide de pascal ---------------------------------*/

/*
vector< long long int> filas,v1;

int i=0,fila;

void imprimevector(vector<long long int> filas)
{
	vector<unsigned long long int>::iterator it=filas.begin();

	for(it;it<filas.end();it++)
	{
		cout<<*it<<" ";
	}
}

unsigned long long int factorial(long long int a)
{
	unsigned long long int factorial=1;

	for(int i=1;i<=a;i++)
	{
		factorial=factorial*i;
	}

	return factorial;
}

unsigned long long int C(int a, int b)
{
	// La expresión general del cálculo del binomial es C(n,k) = (n k) = n!/k!(n-k)!
	int num=0,den=0,rest=0;
	long long int m=0;

	num =  factorial(a); 
	den =  factorial(b);
	rest=	factorial(a-b);
	
	m = num/(rest*den);

	return m;
}

int main()
{
	//La expresión general del cálculo del binomial es C(n,k) = (n k) = n!/k!(n-k)!

	cout<<"digite la cantidad de filas de la piramide de pascal que desea imprimir: ";cin>>fila;

	cout<<"\nEl resultado del factorial es: "<<factorial(fila)<<endl;
	
	for(int j=0;j<=fila;j++)
		{
			v1.push_back(j);
		}

	cout<<"Los valores contenidos en el vector son; "; imprimevector(v1);cout<<endl;

	
	int k;  
	for(int k=0;k<=fila;k++)
	{	
		for(int l=0;l<=k;l++)
			{
			filas.push_back(C(k,l));
			}
	cout<<"Fila n°"<<k<<"\t";imprimevector(filas);cout<<endl;
	filas.clear();
	}
	
	
//	cout<<endl;
//	for(int k=0;k<=fila;k++)
//	{	
//		for(int l=0;l<=k;l++)
//			{
//			cout<<"Fila n°"<<k<<"\t"<<"(k,l)"<<"= ("<<k<<","<<l<<")"<<endl;
//			filas.push_back(C(k,l));
//			
//			}
//	filas.clear();
//	}
//	
//
//	int k; k=15;
//		for(int l=0;l<=k;l++)
//			{
//			filas.push_back(C(k,l));
//			}
//	cout<<"Fila n°"<<k<<"\t";imprimevector(filas);cout<<endl;
//	filas.clear();
	return 0;
}
*/

/*------------------------------------------------------------------ Recursividad de la suma ---------------------------------------------------------*/

/*
vector<int> numero;

int n,Suma=0;

int calcularSuma(vector<int> numero)
{
    vector<int>::iterator it1=numero.begin();

    int Suma=0;
    for(it1; it1<numero.end(); it1++)
    {
        Suma = Suma + (*it1);
    }
    return Suma;
}

void llenarvector(int n)
{
	for(int i=0;i<=n;i++)
	{
		numero.push_back(i);
	}
}

void parOimpar(vector<int> numero)
{	
	vector<int>::iterator it=numero.begin();

	for(it;it<numero.end();it++)
	{
		cout<<"\nEl elemento número "<<*it<<" del vector es";
		if (*it%2==0 || *it==0)
		{
			cout<<" par"<<endl;
		}
		else
		{
			cout<<" impar"<<endl;
		}
	}
}

int main()
{
	int op;
	do{
	cout<<"Ingrese el número hasta el cual desea hacer la suma; ";cin>>n;
	llenarvector(n);
	
	cout<<"El resultado de la suma de los vectores es: "<<calcularSuma(numero)<<endl;

	parOimpar(numero);

	cout<<"\nDigite 1 si desea salir, 0 si desea repetir algún cálculo:"<<endl;
	cin>>op; 

	}
	while(op!=0);

	return 0;
}
*/

/*------------------------------------------------------------------ Intercambio de valores ---------------------------------------------------------*/

/*
void intercambio(float num1,float num2)
{
	float aux;

	aux = num1;
	num1 = num2;
	num2 = aux;

	cout<<"Nuevo valor de num1: "<<num1<<endl;
	cout<<"Nuevo valor de num2: "<<num2<<endl;
}

int main()
{
	float num1 = 20.8, num2= 6.78;

	cout<<"El valor de num1: "<<num1<<endl;
	cout<<"El valor de num2: "<<num2<<endl;

	intercambio(num1,num2);
}

*/

/*------------------------------------------------------------------  ---------------------------------------------------------*/

/*
vector<int> numero; 

void llenarvector(int n)
{
	for(int i=0;i<=n;i++)
	{
		numero.push_back(i);
	}
}

void ordeninverso(vector<int> numero)
{
	reverse(numero.begin(),numero.end());
	for(auto x:numero){cout<<" "<<x;}
}

int main()
{
	int n;

	cout<<"ingrese el número de elementos que desea imprimir: ";cin>>n;
	llenarvector(n);
	ordeninverso(numero);
	return 0;
}
*/

/*------------------------------------------------------------------ Class  ---------------------------------------------------------*/

/*
class persona
{
	private: //Atributos (encapsulación y abstracción)
		int  edad;
		string nombre;

	public: //metodos
		persona(int, string); //Constructor de la clase

		void leer();
		void correr();
};
// Constructor nos sirve para inicializar los atributos

persona::persona(int _edad, string _nombre)
{
	edad = _edad;
	nombre = _nombre;
}

void persona::leer()
{
	cout<<"Soy "<<nombre<<" y estoy leyendo un libro"<<endl;
};

void persona::correr()
{
	cout<<"Soy "<<nombre<<" y estoy corriendo una maratón y tengo "<<edad<<endl;
}

int main()
{
	persona p1 = persona(20,"alejandro");
	persona p2 = persona(19,"Juan");
	persona p3 = persona(18,"Camila");
	p1.leer();
	p1.correr();
	p2.leer();
	p2 .correr();
	p3.leer();
	p3.correr();

	return 0;
}
*/

/*------------------------------------------------------------------ Class example 2  ---------------------------------------------------------*/

/*
class rectangulo
{
	private:
		float largo;
		float ancho;
	public:
		rectangulo(float,float);
		void perimetro();
		void area();
};

rectangulo::rectangulo(float _largo,float _ancho)
{
	largo = _largo;
	ancho = _ancho;
}

void rectangulo::perimetro()
{
	float _perimetro;
	_perimetro = 2*(largo+ancho);
	cout<<"El perimetro es: "<<_perimetro<<endl;
}

void rectangulo::area()
{
	float _area;
	_area = largo*ancho;
	cout<<"El area es: "<<_area<<endl;
}

int main()
{
	rectangulo r1(11,7);
	r1.perimetro();
	r1.area();

	return 0;
}
*/

/*------------------------------------------------------------------ Class example 3  ---------------------------------------------------------*/

/*
class fecha{
	
	private: 		int dia,mes,anio;
	public:
		fecha(int,int,int); //Constructor 1
		fecha(long); //Constructor 2
		void mostrarFecha();
};

// Constructor 1
fecha::fecha(int _dia,int _mes, int _anio)
{
	anio = _anio;
	dia  = _dia;
	mes  = _mes;
}

// Constructor 2
fecha::fecha(long fecha)
{
	anio = int (fecha/10000);
	mes  = int((fecha-anio*10000)/100);
	dia  = int((fecha-anio*10000)-mes*100);
}
void fecha::mostrarFecha()
{
	cout<<"La fecha es: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
}

int main()
{
	fecha hoy(9,1,2017);
	fecha ayer(20180723);
	hoy.mostrarFecha();
	ayer.mostrarFecha();

	return 0;
}
*/

/*------------------------------------------------------------------ Class example  4 ---------------------------------------------------------*/

/*class tiempo
{
	private:
		int horas, minutos, segundos;
	public:
		tiempo(int,int,int);
		tiempo(int);
		tiempo(long);
		void mostrarHora();
};

tiempo::tiempo(int _horas, int _minutos, int _segundos)
{
	horas    = _horas;
	minutos  = _minutos;
	segundos = _segundos;
}

tiempo::tiempo(int Tsec)
{
	
	horas = Tsec/3600;
	Tsec %= 3600;
	minutos = Tsec/60;
	segundos = Tsec%60;
}

void tiempo::mostrarHora()
{
	cout<<"La hora es: "<<horas<<" : "<<minutos<<" : "<<segundos<<endl;
}

int main()
{
	tiempo horaActual(10,24,23);
	tiempo haceunahora(55000);

	haceunahora.mostrarHora();
	horaActual.mostrarHora();

	return 0;
}
*/


/*------------------------------------------------------------------ Class example  5 ---------------------------------------------------------*/

/*
class perro
{
	private: 
		string nombre, raza;
	public:
		perro(string, string); //Constructor
		~perro(); //Destructor
		void mostrarDatos();
		void jugar();
};

perro::perro(string _nombre, string _raza)
{
	nombre =  _nombre;
	raza   =  _raza;
}

// Destructor 
perro::~perro(){}

void perro::mostrarDatos()
{
	cout<<"El nombre del perro es: "<<nombre<<endl;
	cout<<"Y su raza es: "<<raza<<endl;
}

void perro::jugar()
{
	cout<<"El perro "<<nombre<<" está jugando"<<endl;
}

int main()
{
	perro perro1("Fido","Doberman");

	perro1.mostrarDatos();
	perro1.jugar();
	perro1.~perro(); //Destruyendo el objeto;

	return 0;
}
*/

/*------------------------------------------------------------------ Class example  6 ---------------------------------------------------------*/

/*
class punto
{
	private:
		int x,y;
	public:
		punto();
		void setPunto(int , int);
		int getPuntoX();
		int getPuntoY();
};

punto::punto()
{

}

void punto::setPunto(int _x, int _y)
{
	x  = _x;
	y  = _y;
}

int punto::getPuntoX()
{
	return x;
}

int punto::getPuntoY()
{
	return y;
}

int main()
{
	punto punto1;
	punto1.setPunto(15,10);

	cout<<punto1.getPuntoX()<<endl;
	cout<<punto1.getPuntoY()<<endl;

	return 0;
}
*/

/*------------------------------------------------------------------ Class example 7 ------------------------------------------------------------------*/

/*
class Persona
{
	private:
		int edad;
		string nombre;
	public:
		Persona(string, int);
		void mostrarPersona();
};

class Empleado : public Persona
{
	private:
		float sueldo;
	public:
		Empleado(string, int, float);
		void mostrarEmpleado();
};

class Estudiante : public Persona
{
	private:
		float notaFinal;
	public:
		Estudiante(string, int, float);
		void mostrarEstudiante();
};

class Universitario : public Estudiante
{
	private:
		string Carrera;
	
	public:
		Universitario(string, int, float, string); //REcordar poner los atributos de las clases donde de la que se hereda esta.
		void mostrarUniversitario();

};

Estudiante::Estudiante(string _nombre, int _edad, float _notaFinal) : Persona(_nombre,_edad)
{
	notaFinal = _notaFinal;
}

Persona::Persona(string _nombre, int _edad)
{
	nombre = _nombre;
	edad   = _edad;
}

Universitario::Universitario(string _nombre, int _edad, float _notaFinal, string _carrera) : Estudiante(_nombre, _edad, _notaFinal)
{
	Carrera  = _carrera;
}


Empleado::Empleado(string _nombre,int _edad, float _sueldo) : Persona(_nombre,  _edad)
{
	sueldo = _sueldo;
}

void Persona::mostrarPersona()
{
	cout<<"El nombre de la persona es: "<<nombre<<" y su edad es: "<<edad;
}

void Empleado::mostrarEmpleado()
{	
	mostrarPersona();
	cout<<" y su sueldo es: "<<sueldo;
}

void  Estudiante::mostrarEstudiante()
{
	mostrarPersona();
	cout<<" y su nota final es: "<<notaFinal<<endl;
}

void Universitario::mostrarUniversitario()
{	
	mostrarEstudiante();
	cout<<"y su carrera es: "<<Carrera<<endl;
}

int main()
{
	Empleado empleado1("Carlos",35,1300);
	cout<<"-Empleado-"<<endl;
	empleado1.mostrarEmpleado();
	cout<<endl;

	Universitario universitario1("Aldo",24,43.1,"Ingeniería Civil en Telecomunicaciones");
	cout<<"\n - Estudiante Universitario - "<<endl;
	universitario1.mostrarUniversitario();
	cout<<endl;

	Estudiante estudiante1("Ignacio",26,39.6);
	cout<<"\n -Estudiante apretando el culo- "<<endl;
	estudiante1.mostrarEstudiante();


	return 0;
}
*/ 

/*------------------------------------------------------------------ Class example 7 virtual ------------------------------------------------------------------*/


/*
class Persona
{
	private:
		int edad;
		string nombre;
	public:
		Persona(string, int);
		virtual void mostrar();
};

class Empleado : public Persona
{
	private:
		float sueldo;
	public:
		Empleado(string, int, float);
		void mostrar();
};

class Estudiante : public Persona
{
	private:
		float notaFinal;
	public:
		Estudiante(string, int, float);
		void mostrar();
};

class Universitario : public Estudiante
{
	private:
		string Carrera;
	public:
		Universitario(string, int, float, string); //Recordar poner los atributos de las clases donde de la que se hereda esta.
		void mostrar();
};

Persona::Persona(string _nombre, int _edad)
{
	nombre = _nombre;
	edad   = _edad;
}

Empleado::Empleado(string _nombre,int _edad, float _sueldo) : Persona(_nombre,  _edad)
{
	sueldo = _sueldo;
}

Estudiante::Estudiante(string _nombre, int _edad, float _notaFinal) : Persona(_nombre,_edad)
{
	notaFinal = _notaFinal;
}

Universitario::Universitario(string _nombre, int _edad, float _notaFinal, string _carrera) : Estudiante(_nombre, _edad, _notaFinal)
{
	Carrera  = _carrera;
}

void Persona::mostrar()
{
	cout<<"El nombre de la persona es: "<<nombre<<" y su edad es: "<<edad;
}

void Empleado::mostrar()
{	
	Persona::mostrar();
	cout<<" y su sueldo es: "<<sueldo;
}

void  Estudiante::mostrar()
{
	Persona::mostrar();
	cout<<" y su nota final es: "<<notaFinal<<endl;
}

void Universitario::mostrar()
{	
	Persona::mostrar();
	cout<<"y su carrera es: "<<Carrera<<endl;
}

int main()
{
	Empleado empleado1("Carlos",35,1300);
	cout<<"-Empleado-"<<endl;
	empleado1.mostrar();
	cout<<endl;

	Universitario universitario1("Aldo",24,43.1,"Ingeniería Civil en Telecomunicaciones");
	cout<<"\n - Estudiante Universitario - "<<endl;
	universitario1.mostrar();
	cout<<endl;

	Estudiante estudiante1("Ignacio",26,39.56);
	cout<<"\n -Estudiante apretando el culo- "<<endl;
	estudiante1.mostrar();

	return 0;
}
*/

/*------------------------------------------------------------------ Class example 7 virtual ------------------------------------------------------------------*/

/*
class Animal //Clase padre
{
	private:
		int edad;
	public:
		Animal(int);
		virtual void Comer();
};

class Humano : public Animal //Clase Hija
{
	private:
		string nombre;
	public:
		Humano(int, string);
		void Comer();
};

class Perro : public Animal
{
	private:
		string nombre,raza;
	public:	
		Perro(int, string,string);
		void Comer();
};

Animal::Animal(int _edad)
{
	edad = _edad;
}

Humano::Humano(int _edad, string _nombre) : Animal(_edad)
{
	nombre = _nombre;
}

Perro::Perro(int _edad, string _nombre, string _raza) : Animal(_edad)
{
	nombre = _nombre;
	raza   = _raza;
}

void Animal::Comer()
{
	cout<<"Yo como ";
}

void Humano::Comer()
{	
	Animal::Comer();
	cout<<"En una mesa, sentado en una silla "<<endl;
}

void Perro::Comer()
{
	Animal::Comer();
	cout<<"En el suelo, con mi plato"<<endl;
}

int main()
{	
	Animal *animales[2];

	animales[0] = new Perro(5,"Boby","Pastor Alemán");
	animales[1] = new Humano(24,"Aldo");

	animales[0] -> Comer();
	animales[1] -> Comer();

	return 0;
}
*/