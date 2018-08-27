#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <string>


using namespace std;

//vector<string> codificador(vector<string> entrada, int n, int d);

int main()
{
    // Archivo de entrada
    ifstream entradatxt("entrada.txt");
    string temp;
    string temp2;
    vector<string> entrada;
    string::iterator itertemp;
    int n;
    int d;

    int opcion;

    while(opcion != 1 && opcion != 2){
    cout << "Si desea CODIFICAR marque 1" <<endl;
    cout << "Si desea DECODIFICAR marque 2"<<endl;
    cout << endl;
    cin >> opcion;

    if(opcion != 1 && opcion != 2){
        cout << "Opción invalida" <<endl;
        cout << endl;
    }
    }

    cout << endl;
    cout << "INGRESE NUMERO DE FILAS: ";
    cin >> n;
    cout << "INGRESE DESPLAZAMIENTO: ";
    cin >>d;

    int numerofilas = n;
    int numerodesplazamientos = d;

    //desplazamientos
    string offset = "-";
    if(d!=0){
        for(int k= 0; k<d; k++){
            entrada.push_back(offset);
        }
    }


    //Se pasa caracter a caracter el texto de entrada.txt a el vector de strings entrada.
    while(entradatxt>>temp)
    {
        for(itertemp= temp.begin(); itertemp != temp.end(); ++itertemp){
            temp2 = *(itertemp);
            entrada.push_back(temp2);
        }
    }
    entradatxt.close();

// CODIFICADOR

    vector<string>::iterator itentrada = entrada.begin();
    vector<string>::iterator itendentrada = entrada.end();
    vector<string> salida;
    vector<int> vectorcontador;

    //posiciones nmax (2n-2)

    int contador = 0;
    string vacio = "/";
    int aux=1;
    while(aux<=entrada.size()){
        salida.push_back(*(itentrada+(aux-1)));
        contador++;
        fill(itentrada+(aux-1),itentrada+(aux),vacio);
        aux = aux + 2*n - 2;
    }

    itentrada = entrada.begin();
    itendentrada = remove(itentrada,itendentrada,vacio);
    vectorcontador.push_back(contador);
    --n;

    //posiciones 1<n<nmax (2n-2 y 2n-1)

    while(n!=1){
        contador = 0;
        aux=1;
        salida.push_back(*(itentrada+(aux-1)));
        if (*(itentrada+(aux-1)) != vacio){
            contador++;
        }
        fill(itentrada+(aux-1),itentrada+(aux),vacio);
        aux = aux + 2*n - 2;

        while(aux<entrada.size()){

            salida.push_back(*(itentrada+(aux-1)));
            if (*(itentrada+(aux-1)) != vacio){
                contador++;
            }
            salida.push_back(*(itentrada+(aux)));
            if (*(itentrada+(aux)) != vacio){
                contador++;
            }
            fill(itentrada+(aux-1),itentrada+(aux+1),vacio);
            aux = aux + 2*n - 1;
        }

        itentrada = entrada.begin();
        itendentrada = remove(itentrada,itendentrada,vacio);
        vectorcontador.push_back(contador);
        --n;
    }

    //ultima linea
    contador = 0;
    for(itentrada;itentrada!=itendentrada;itentrada++){
        salida.push_back(*itentrada);
        contador++;
        fill(itentrada,itentrada+1,vacio);
    }
    vectorcontador.push_back(contador);

    vector<string> retorno;
    vector<string>::iterator itsalida = salida.begin();
    vector<string>::iterator itendsalida;


    itendsalida = remove(itsalida,salida.end(),offset);

    itendsalida = remove(itsalida,itendsalida,vacio);



    if(opcion==1){

        ofstream salidatxt("salida.txt");
        for(itsalida;itsalida!=itendsalida;++itsalida){
            retorno.push_back(*itsalida);
            salidatxt << *itsalida;
        }

        vector<string>::iterator itret = retorno.begin();
        vector<string>::iterator itretend = retorno.end();

        salidatxt.close();

        cout << endl;
        cout << "La codificación de entrada.txt con " << numerofilas << " filas y " << d << " desplazamientos es:"<<endl;

        for(itret;itret!=itretend;itret++){
            cout << *itret;
        }
        cout << endl;

        return 0;

    }

    // DECODIFICADOR

    else{
        // Archivo de entrada
        ifstream entradatxtD("entrada.txt");
        string tempD;
        string temp2D;
        vector<string> entradaD;
        string::iterator itertempD;

        cout << endl;
        cout << "La decodificación de entrada.txt con " << numerofilas << " filas y " << d << " desplazamientos es:"<<endl;


        //desplazamientos

        if(d!=0){
            for(int k= 0; k<d; k++){
                entradaD.push_back(offset);
            }
        }

    //Se pasa caracter a caracter el texto de entrada.txt a el vector de strings entrada.
        while(entradatxtD>>tempD)
        {
            for(itertempD= tempD.begin(); itertempD != tempD.end(); ++itertempD){
                temp2D = *(itertempD);
                entradaD.push_back(temp2D);
            }
        }
        entradatxtD.close();

        vector<string>::iterator eDbegin = entradaD.begin();
        vector<string>::iterator eDend = entradaD.end();
        vector<vector<string>> vectordevectores;
        vector<vector<string>>::iterator vdvbegin = vectordevectores.begin();
        vector<int>::iterator vcbegin = vectorcontador.begin();
        vector<int>::iterator vcend = vectorcontador.end();
        vector<string> tempv;
        string temps;

// primera grupo
        for(int j = 0; j<*vcbegin; j++){

            temps = *(eDbegin+j);
            tempv.push_back(temps);
        }
        vectordevectores.push_back(tempv);
        temps.clear();
        tempv.clear();
        eDbegin = eDbegin + (*vcbegin);

//grupos intermedios, repetir nfilas-2 veces

        int ene = numerofilas-2;

        for(int k =1; k <= ene; k++){

            for(int j = 0; j<*(vcbegin+k); j++){

                temps = *(eDbegin+j);
                tempv.push_back(temps);
            }

            vectordevectores.push_back(tempv);
            temps.clear();
            tempv.clear();
            eDbegin = eDbegin + (*(vcbegin+k));

        }


//ultimo grupo

        vector<string> tempvaux;
        vector<string>::iterator vauxb;
        vector<string>::iterator vauxe;
        temps.clear();
        tempv.clear();

        for(int jk = 1; jk<=*(vcend-1); jk++){
            temps = *(eDend-jk);
            tempvaux.push_back(temps);
        }

        vauxb = tempvaux.begin();
        vauxe = tempvaux.end();

        for(vauxe;vauxe!=vauxb;vauxe--){
            tempv.push_back(*(vauxe-1));
        }

        vectordevectores.push_back(tempv);
        temps.clear();
        tempv.clear();



        vector<string> vectorfinal;
        vector<vector<string>>::iterator itergrande;
        vector<string>::iterator iterchico;
        string::iterator itermaschico;

        itergrande = next((vectordevectores.begin()),0); // se mueve por bloque (n bloques, n filas)
        iterchico = next(((*itergrande).begin()),0); //se mueve dentro de cada subdivisión
        itermaschico = (*iterchico).begin(); //este es el string, siempre será begin
        int largov = (vectordevectores).size();




        int pr = 0;
        pr = pr + (d-1); //porque con 6 - 2 salia todo bien, salvo las letras del primer grupo
        int dlm = 0;
        int ult = 0;

        ofstream salidatxt("salida.txt");

        salidatxt << *itsalida;



        for(int j = 0; j<30  ; j++){ //fui probando distintos valores de j hasta el maximo sin Segmentation Fault (Core Dumped)

//PRIMERO
            itergrande = next((vectordevectores.begin()),0);
            iterchico = next(((*itergrande).begin()),pr);
            itermaschico = (*iterchico).begin();
            cout << *itermaschico;
            salidatxt << *itermaschico;
            pr++;

//DEL MEDIO
            for(int j = 1; j<numerofilas-1; j++){
                itergrande = next((vectordevectores.begin()),j);
                iterchico = next(((*itergrande).begin()),dlm);
                itermaschico = (*iterchico).begin();
                cout << *itermaschico;
                salidatxt << *itermaschico;
            }
            dlm++;
//ULTIMO
            itergrande = next((vectordevectores.begin()),numerofilas-1);
            iterchico = next(((*itergrande).begin()),ult);
            itermaschico = (*iterchico).begin();
            cout << *itermaschico;
            salidatxt << *itermaschico;
            ult++;

//DEL MEDIO CON REVERSO
            vector<string> reverso;
            vector<string> reversoout;
            string auxrev;

            for(int j = 1; j<numerofilas-1; j++){
                itergrande = next((vectordevectores.begin()),j);
                iterchico = next(((*itergrande).begin()),dlm);
                itermaschico = (*iterchico).begin();
                auxrev = *itermaschico;
                reverso.push_back(auxrev);
            }

            vector<string>::iterator rauxb = reverso.begin();
            vector<string>::iterator rauxe = reverso.end();

            for(rauxe;rauxe!=rauxb;rauxe--){
            reversoout.push_back(*(rauxe-1));
            salidatxt << (*(rauxe-1));
            }

            vector<string>::iterator rob = reversoout.begin();
            vector<string>::iterator roe = reversoout.end();
            for(rob ;rob!=roe; rob++){
                cout << *rob;
            }
            dlm++;

        }

        salidatxt.close();


        return 0;
    }

    return 0;
}
