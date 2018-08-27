//#include <iostream>
//#include <vector>
//#include <iterator>
//#include <list>
//#include <algorithm>
//
//
//using namespace std;
//
//int main()
//{
//    vector<int> v1, v2; //Se crea un vector de enteros
//    long int i,num=0,dig;
//    for(i=(15800000-1);i>=0;i--)
//    {
//         while(num!=0)
//        {
//           dig = num%10;
//           v1.push_back(dig); //Se va rellenando el vector con los digitos
//           num = num/10;
//        }
//
//        num=i;
//
//    }
//    reverse(v1.begin(),v1.end());//El vector se invierte, pues estaba al reves por las iteraciones del ciclo for
//
//
//    int cont1=0,cont2=0;
//    vector<int>::const_iterator iter=v1.begin();
//    int largo = v1.size();
//    int cc = 0; long int numql = 15800000; long int contaql = 0;
//
//       while (iter != v1.end())
//        {
//            largo = v1.size();
//
//            if ((cc + 20) == largo)
//            {   cout<<"hollaaaaaaa"<<endl;
//
//                int j = cc -1;
//                vector<int>::const_iterator iter5=v1.end();
//                iter5--;iter5--;iter5--;iter5--;iter5--;  iter5--;iter5--;iter5--;iter5--;iter5--;  iter5--;iter5--;iter5--;iter5--;iter5--;  iter5--;iter5--;iter5--;iter5--;iter5--;
//                v1.erase(v1.begin(),iter5);cout << v1.size()<<"--"<<endl;
//                v2 = v1;
//                num  = numql;
//                for(i=num;i<(numql+15800000);i++)
//                    {
//                         while(num!=0)
//                        {
//                           dig = num%10;
//                           v2.push_back(dig); //Se va rellenando el vector con los digitos
//                           num = num/10;
//                        }
//                        num=i;
//                    }
//
//            v1.clear();
//            v1 = v2;           cout<<v1.size()<<endl;
//            iter = v1.begin();
//            numql = numql + 15800000;
//            cout<<numql<<endl;cc = 0;
//            }
//
//            if (*(iter) == 1&&
//               *(iter+1) == 9&&
//               *(iter+2) == 6&&
//               *(iter+3) == 8 &&
//               *(iter+4) == 3)
//                {
//                     cont1++; //cont1: contador que lleva la cuenta de cuantas veces a ocurrido el numero
//                }
//                cont2++;//cont2:Este contador lleva la cuenta de las veces que ha ocurridd el ciclo
//
//
//            if(cont1==19683){cout<<"HOLAAAA";break;}//Se corta el ciclo en la n-sima aparicion de n
//            ++iter;
//            cc = cc + 1;
//        }
//        cout<<cont2<<"<="<<cont1<<endl;
//    return 0;
//}

/** Codigo definitivo **/

//#include <iostream>
//#include <vector>
//#include <iterator>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    vector<int> v1, v2; //Se crea un vector de enteros
//    long int i,num=0,dig;
//    for(i=15800000;i>=0;i--)
//    {
//         while(num!=0)
//        {
//           dig = num%10;
//           v1.push_back(dig); //Se va rellenando el vector con los dígitos
//           num = num/10;
//        }
//        num=i;
//    }
//    reverse(v1.begin(),v1.end());//El vector se invierte, pues estaba al reves por las iteraciones del ciclo for
//    int cont1=0,cont2=0;
//    vector<int>::const_iterator iter=v1.begin();
//    int largo = v1.size();
//    int cc = 0; long int numl = 15800000; long int contaql = 0;
//
//       while (iter != v1.end())
//        {
//            largo = v1.size();
//            if ((cc + 20) == largo)
//            {	int j = cc -1;
//                vector<int>::const_iterator iter5=v1.end();
//                iter5--;iter5--;iter5--;iter5--;iter5--;  iter5--;iter5--;iter5--;iter5--;iter5--;  iter5--;iter5--;iter5--;iter5--;iter5--;  iter5--;iter5--;iter5--;iter5--;iter5--;
//                v1.erase(v1.begin(),iter5);cout << v1.size()<<"--"<<endl;
//                v2 = v1;
//                num  = numl;
//                for(i=num;i<=(numl+15800000);i++)
//                    {
//                         while(num!=0)
//                        {
//                           dig = num%10;
//                           v2.push_back(dig); //Se va rellenando el vector con los digitos
//                           num = num/10;
//                        }
//                        num=i;
//                    }
//            v1.clear();
//            v1 = v2;           cout<<v1.size()<<endl;
//            iter = v1.begin();
//            numl = numl + 15800000;cout<<numl<<endl;cc = 0;
//            }
//
//            if (*(iter) == 1&&
//               *(iter+1) == 9&&
//               *(iter+2) == 6&&
//               *(iter+3) == 8 &&
//               *(iter+4) == 3)
//                {
//                     cont1++; //cont1: contador que lleva la cuenta de cuantas veces a ocurrido el numero
//                }
//                cont2++;//cont2:Este contador lleva la cuenta de las veces que ha ocurridd el ciclo
//            if(cont1==19683){cout<<"HOLAAAA";break;}//Se corta el ciclo en la n-sima aparicion de n
//            ++iter;
//            cc = cc + 1;
//        }
//        cout<<cont2<<"<="<<cont1<<endl;//1539837210
//    return 0;
//}

/** Codigo Prueba **/


#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <algorithm>


using namespace std;

int main()
{
    vector<int> v1; //Se crea un vector de enteros
    int i,num=0,dig;
    for(i=100000000;i>=0;i--)
    {
         while(num!=0)
        {

           dig = num%10;
           v1.push_back(dig); //Se va rellenando el vector con los digitos
           num = num/10;
        }

        num=i;

    }
    reverse(v1.begin(),v1.end());//El vector se invierte, pues estaba al reves por las iteraciones del ciclo for


    int cont1=0,cont2=0;
    vector<int>::const_iterator iter=v1.begin();

       while (iter != v1.end())
        {
            if (*(iter) == 7&&
               *(iter+1) == 7&&
               *(iter+2) == 8&&
               *(iter+3) == 0)
                {
                     cont1++; //cont1: contador que lleva la cuenta de cuantas veces a ocurrido el numero
                }
                cont2++;//cont2:Este contador lleva la cuenta de las veces que ha ocurridd el ciclo


            if(cont1==7780){break;}//Se corta el ciclo en la n-sima aparicion de n
            ++iter;
        }
        cout<<cont2<<"<="<<cont1<<endl;

    return 0;
}
