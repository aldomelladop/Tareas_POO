#include<iostream>
#include<stdlib.h>

using namespace std;

class rectangulo
{
	private:
		float largo;
		float ancho;
	public:
		rectangulo(float,float);
		float area();
		float perimetro();

};

rectangulo::rectangulo(float _largo, float _ancho)
{
	largo = _largo;
	ancho = _ancho;
}

float rectangulo::area()
{
	float area;

	area = largo*ancho;

	return area;
}

float rectangulo::perimetro()
{
	float perimetro;

	perimetro = 2*(largo+ancho);

	return perimetro;
}

int main()
{
	float area,perimetro;

	rectangulo  r1 =  rectangulo(20,15);
	area = r1.area();
	cout<<" El area del rectangulo 1 es: "<<area<<endl;

	perimetro = r1.perimetro();
	cout<<" El perimetro del rectangulo 1 es: "<<perimetro<<endl;

	return 0;
}