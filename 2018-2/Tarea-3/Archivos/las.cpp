// Felipe Ignacio Lamas Silva.

#include <iostream>
#include <vector>

using namespace std;

//Codigo que implementa los primeros 25 terminos de la secuencia Look and Say. Ademas, calcula sus largos
// y los numeros de 1s, 2s, 3s y 4s presentes en cada uno.
int main()
{
    cout << "Primeros 25 elementos de la Secuencia 'Look and Say':" << endl << endl;

    // Inicializando primer elemento de secuencia Look And Say.
    vector<int> L{1}, Ltemp;

    // Desplegando en consola primer elemento y su largo.
    cout << "L1 = " << L.at(0) << endl;
    cout << "Largo de L1 = 1";

    // Desplegando en consola numero de 1s, 2s, 3s y 4s presentes en el primer elemento.
    cout << endl << "En L" << (1) << ":";
    cout << endl << "El numero de 1s es: 1";
    cout << endl << "El numero de 2s es: 0";
    cout << endl << "El numero de 3s es: 0";
    cout << endl << "El numero de 4s es: 0" << endl;

    // Contadores temporales y generales de 1s, 2s, 3s y 4s.
    int contador1s = 0, contador2s = 0, contador3s = 0, contador4s = 0;
    int contadorGeneral1s = 0, contadorGeneral2s = 0, contadorGeneral3s = 0, contadorGeneral4s = 0;

    // Ciclo para calculo de L2 a L25.
    for(int i = 1; i <= 24; i++)
    {
        // Ciclo que utiliza elemento anterior para crear el siguiente.
        for(vector<int>::iterator iter = L.begin(); iter != L.end(); iter++)
        {
            if((*iter) == 1) // Si lo apuntado por el iterador es igual a 1, el contador temporal de 1s se
                // incrementara en 1.
            {
                contador1s++;
            }
            if(((*iter) == 1) && contador2s != 0) // En el caso que el elemento encontrado sea distinto al anterior,
                // esto es los valores encontrados anteriormente fueron solo 2s (contador de 2s es distinto de cero),
                // se agrega el numero de 2s encontrados (y su indicador: mediante Ltemp.push_back(2)) al vector
                // auxiliar Ltemp.
            {
                Ltemp.push_back(contador2s);
                Ltemp.push_back(2);
                contador2s = 0;
            }
            if(((*iter) == 1) && contador3s != 0) // En el caso que el elemento encontrado sea distinto al anterior,
                // esto es los valores encontrados anteriormente fueron solo 3s (contador de 3s es distinto de cero),
                // se agrega el numero de 3s encontrados (y su indicador: mediante Ltemp.push_back(3)) al vector
                // auxiliar Ltemp.
            {
                Ltemp.push_back(contador3s);
                Ltemp.push_back(3);
                contador3s = 0;
            }
            if(((*iter) == 1) && contador4s != 0) // En el caso que el elemento encontrado sea distinto al anterior,
                // esto es los valores encontrados anteriormente fueron solo 4s (contador de 4s es distinto de cero),
                // se agrega el numero de 4s encontrados (y su indicador: mediante Ltemp.push_back(4)) al vector
                // auxiliar Ltemp.
            {
                Ltemp.push_back(contador4s);
                Ltemp.push_back(4);
                contador4s = 0;
            }
            if((*iter) == 2) // Caso analogo al efectuado para (*iter) == 1.
            {
                contador2s++;
            }
            if(((*iter) == 2) && (contador1s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador1s);
                Ltemp.push_back(1);
                contador1s = 0;
            }
            if(((*iter) == 2) && (contador3s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador3s);
                Ltemp.push_back(3);
                contador3s = 0;
            }
            if(((*iter) == 2) && (contador4s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador4s);
                Ltemp.push_back(4);
                contador4s = 0;
            }
            if((*iter) == 3) // Caso analogo al efectuado para (*iter) == 1.
            {
                contador3s++;
            }
            if(((*iter) == 3) && (contador1s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador1s);
                Ltemp.push_back(1);
                contador1s = 0;
            }
            if(((*iter) == 3) && (contador2s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador2s);
                Ltemp.push_back(2);
                contador2s = 0;
            }
            if(((*iter) == 3) && (contador4s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador4s);
                Ltemp.push_back(4);
                contador4s = 0;
            }
            if((*iter) == 4) // Caso analogo al efectuado para (*iter) == 1.
            {
                contador4s++;
            }
            if(((*iter) == 4) && (contador1s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador1s);
                Ltemp.push_back(1);
                contador1s = 0;
            }
            if(((*iter) == 4) && (contador2s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador2s);
                Ltemp.push_back(2);
                contador2s = 0;
            }
            if(((*iter) == 4) && (contador3s != 0)) // Caso similar al efectuado para if(((*iter) == 1) && contador2s != 0).
            {
                Ltemp.push_back(contador3s);
                Ltemp.push_back(3);
                contador3s = 0;
            }
            if(iter == (L.end() - 1))
            {
                Ltemp.push_back(contador1s); // Pues, por construccion, la secuencia siempre terminara con al menos un 1.
                Ltemp.push_back(1);
                contador1s = 0;
            }
        }
        // Respaldando contenido de Ltemp.
        L = Ltemp;
        // Borrando el contenido de vector auxiliar Ltemp.
        Ltemp.clear();

        // Desplegando en consola elemento Li+1.
        cout << endl << "L" << (i + 1) << " = ";
        for(int x:L)
        {
            cout << x;
        }
        // Desplegando en consola largo de elemento Li+1.
        cout << endl << "Largo de L" << (i + 1) << " = " << L.size();

        // Contando 1s, 2s, 3s y 4s en elemento Li+1.
        for(vector<int>::iterator iter = L.begin(); iter != L.end(); iter++)
        {
            if((*iter) == 1)
            {
                contadorGeneral1s++;
            }
            if((*iter) == 2)
            {
                contadorGeneral2s++;
            }
            if((*iter) == 3)
            {
                contadorGeneral3s++;
            }
            if((*iter) == 4)
            {
                contadorGeneral4s++;
            }
        }
        // Desplegando en consola numero de 1s, 2s, 3s y 4s en elemento Li+1.
        cout << endl << "En L" << (i + 1) << ":";
        cout << endl << "El numero de 1s es: " << contadorGeneral1s;
        cout << endl << "El numero de 2s es: " << contadorGeneral2s;
        cout << endl << "El numero de 3s es: " << contadorGeneral3s;
        cout << endl << "El numero de 4s es: " << contadorGeneral4s << endl;

        // Borrando contadores generales, para sus calculos en nuevas iteraciones.
        contadorGeneral1s = 0;
        contadorGeneral2s = 0;
        contadorGeneral3s = 0;
        contadorGeneral4s = 0;
    }

    return 0;
}
