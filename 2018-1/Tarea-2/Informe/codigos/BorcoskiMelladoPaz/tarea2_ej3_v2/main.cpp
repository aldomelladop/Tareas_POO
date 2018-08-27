#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <fstream>
#include <list>
#include <ctime>
using namespace std;
list <pair<int,int>> coord(list<int>& pos)//funcion que a partir de una lista con posiciones entrega una lista con coordenadas
{
    list<pair<int,int>> pos_f;
    int f,a,i;
    list<int>::iterator it=pos.begin();
    while(it!=pos.end())
    {
        if(*it!=-1 ||*it!=-2)
        {
                f=((*it)-1)/75;
                a=(*it)-f*75;
                pos_f.push_back(make_pair(f+1,a+1));
        }
        //Para los casos de W,w,K y k
        if(*it==-1){pos_f.push_back(make_pair(0,1));}
        if(*it==-2){pos_f.push_back(make_pair(0,0));}

        it++;
    }

    return pos_f;
}
list<int> decod(list<int>& x) //recibe una lista y transforma las coordenadas en la posicion del donQuijote
{
    list<int>::iterator iter =x.begin(),iter2;
    iter2=iter++;
    list<int> y;
    while(iter!=x.end())
    {
        int pos=(*iter)*75 + *iter2;
        y.push_back(pos);
        iter++;
        iter++;
    }
    return y;
}
int azar(list<int>& x) //funcion que entrega elemento al azar de alguna lista
{
    srand(time(0));
    list<int>:: iterator i_x=x.begin();
    int random=rand()%x.size();
    i_x=next(i_x,random);
    return *i_x;

}
int main()
{
    ifstream donQuijote("pad_tarea2.txt");
    char temp;
    list<char> pad_tarea2,all_chars;
    while(donQuijote >> temp)
    {
        pad_tarea2.push_back(temp);
        all_chars.push_back(temp);
    }
    donQuijote.close();

    all_chars.sort();
    unique(all_chars.begin(),all_chars.end());
    list<char>::iterator it_ac=all_chars.begin();
    it_ac=next(it_ac,45);
    all_chars.erase(it_ac,all_chars.end());
    // Existen 45 caracteres diferentes en el texto

    list<int> enhe,coma,guion,punto,dospuntos,puntocoma,A,B,C,E,F,G,I,M,N,P,Q,S,T,U
    ,guionbajo,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
    int ii;
    list<char>::iterator it_pad=pad_tarea2.begin();
        for(ii=1;ii<=2700;ii++)//ñ
    {
        if('ñ'==*(next(it_pad,ii)))
        {
            enhe.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//,
    {
        if(','==*(next(it_pad,ii)))
        {
            coma.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//-
    {
        if('-'==*(next(it_pad,ii)))
        {
            guion.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//.
    {
        if('.'==*(next(it_pad,ii)))
        {
            punto.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//:
    {
        if(':'==*(next(it_pad,ii)))
        {
            dospuntos.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//;
    {
        if(';'==*(next(it_pad,ii)))
        {
            puntocoma.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//A
    {
        if('A'==*(next(it_pad,ii)))
        {
            A.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//B
    {
        if('B'==*(next(it_pad,ii)))
        {
            B.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//C
    {
        if('C'==*(next(it_pad,ii)))
        {
            C.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//E
    {
        if('E'==*(next(it_pad,ii)))
        {
            E.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//F
    {
        if('F'==*(next(it_pad,ii)))
        {
           F.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//G
    {
        if('G'==*(next(it_pad,ii)))
        {
            G.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//I
    {
        if('I'==*(next(it_pad,ii)))
        {
            I.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//M
    {
        if('M'==*(next(it_pad,ii)))
        {
            M.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//N
    {
        if('N'==*(next(it_pad,ii)))
        {
            N.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//P
    {
        if('P'==*(next(it_pad,ii)))
        {
            P.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//Q
    {
        if('Q'==*(next(it_pad,ii)))
        {
            Q.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//S
    {
        if('S'==*(next(it_pad,ii)))
        {
           S.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//T
    {
        if('T'==*(next(it_pad,ii)))
        {
            T.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//U
    {
        if('U'==*(next(it_pad,ii)))
        {
            U.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//_
    {
        if('_'==*(next(it_pad,ii)))
        {
            guionbajo.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//a
    {
        if('a'==*(next(it_pad,ii)))
        {
            a.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//b
    {
        if('b'==*(next(it_pad,ii)))
        {
            b.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//c
    {
        if('c'==*(next(it_pad,ii)))
        {
            c.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//d
    {
        if('d'==*(next(it_pad,ii)))
        {
            d.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//e
    {
        if('e'==*(next(it_pad,ii)))
        {
            e.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//f
    {
        if('f'==*(next(it_pad,ii)))
        {
            f.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//g
    {
        if('g'==*(next(it_pad,ii)))
        {
            g.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//h
    {
        if('h'==*(next(it_pad,ii)))
        {
            h.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//i
    {
        if('i'==*(next(it_pad,ii)))
        {
            i.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//j
    {
        if('j'==*(next(it_pad,ii)))
        {
            j.push_back(ii);
        }
    }

        for(ii=1;ii<=2700;ii++)//l
    {
        if('l'==*(next(it_pad,ii)))
        {
            l.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//m
    {
        if('m'==*(next(it_pad,ii)))
        {
            m.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//n
    {
        if('n'==*(next(it_pad,ii)))
        {
            n.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//o
    {
        if('o'==*(next(it_pad,ii)))
        {
            o.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//p
    {
        if('p'==*(next(it_pad,ii)))
        {
            p.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//q
    {
        if('q'==*(next(it_pad,ii)))
        {
            q.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//r
    {
        if('r'==*(next(it_pad,ii)))
        {
            r.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//s
    {
        if('s'==*(next(it_pad,ii)))
        {
            s.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//t
    {
        if('t'==*(next(it_pad,ii)))
        {
            t.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//u
    {
        if('u'==*(next(it_pad,ii)))
        {
            u.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//v
    {
        if('v'==*(next(it_pad,ii)))
        {
            v.push_back(ii);
        }
    }

        for(ii=1;ii<=2700;ii++)//x
    {
        if('x'==*(next(it_pad,ii)))
        {
            x.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//y
    {
        if('y'==*(next(it_pad,ii)))
        {
            y.push_back(ii);
        }
    }
        for(ii=1;ii<=2700;ii++)//z
    {
        if('z'==*(next(it_pad,ii)))
        {
            z.push_back(ii);
        }
    }


    map<char,list<int>> letras;
    letras['ñ']=enhe;letras[',']=coma;letras['-']=guion;letras['.']=punto;letras[':']=dospuntos;
    letras[';']=puntocoma;letras['A']=A;letras['B']=B;letras['C']=C;letras['E']=E;letras['F']=F;
    letras['G']=G;letras['I']=I;letras['M']=M;letras['N']=N;letras['P']=P;letras['Q']=Q;
    letras['S']=S;letras['T']=T;letras['U']=U;letras['_']=guionbajo;letras['a']=a;letras['b']=b;
    letras['c']=c;letras['d']=d;letras['e']=e;letras['f']=f;letras['g']=g;letras['h']=h;
    letras['i']=i;letras['j']=j;letras['l']=l;letras['m']=m;letras['n']=n;
    letras['o']=o;letras['p']=p;letras['q']=q;letras['r']=r;letras['s']=s;letras['t']=t;
    letras['u']=u;letras['v']=v;letras['x']=x;letras['y']=y;letras['z']=z;
    letras['w']={-1}; letras['W']={-1}; letras['K']={-2}; letras['k']={-2};
    // Se recibe el texto que se desea encriptar
    ifstream input("entrada.txt");
    ofstream salida("salida.txt");
    char temp1;
    list<char> entrada;
    while(input >> temp1)
    {
        entrada.push_back(temp1);
    }
    input.close();
    list<char>::iterator iter=entrada.begin();
    list<int> entrada_pos;
    list<pair<int,int>> entrada_coord;
    while(iter!=entrada.end())
    {
        if(*iter!='k'||*iter!='K'||*iter!='W'||*iter!='w')

            {
                int cont= azar(letras[*iter]);
                entrada_pos.push_back(cont);
            }
            else
            {
                entrada_pos.push_back(*iter);
            }
            iter++;
    }

    entrada_coord=coord(entrada_pos);

    list<pair<int,int>>::iterator iter_coord=entrada_coord.begin();

        for(iter_coord=entrada_coord.begin(); iter_coord!=entrada_coord.end();iter_coord++)
    {
        salida<<"("<<(*iter_coord).first<<","<<(*iter_coord).second<<")";
    }
    salida.close();
    //Ahora hacemos la parte decodificadora, sabemos que la lista viene con comas y parentesis, asique los eliminamos
    ifstream input_2("salida.txt");
    ofstream salida_decod("salida_decod.txt");
    char temp2;
    list<char> salida2;
    while(input_2 >> temp2)
    {
        salida2.push_back(temp2);
    }
    input_2.close();

    salida2.remove('(');
    salida2.remove(',');
    salida2.remove(')');
    //transformar la lista de char a int
    list<char>::iterator iter_s2=salida2.begin();
    list<int> salida2_int;
    while(iter_s2!=salida2.end())
    {
        char aaa=*iter_s2;
        salida2_int.push_back(aaa-48);
        iter_s2++;
    }

    list<int> salida2_decod=decod(salida2_int);
    list<char> decodificado;
    list<int>::iterator it_decod=salida2_decod.begin();
    list<char>::const_iterator it_pad_c=pad_tarea2.begin();
    //se toma la posicion y se guarda en una lista el valor que corresponde a aquella posicion en el texto del quijote
    while(it_decod!=salida2_decod.end())
    {
        decodificado.push_back(*next(it_pad_c,*it_decod-1));
        it_decod++;
    }
    list<char>::iterator i_decodificado=decodificado.begin();
    while(i_decodificado!=decodificado.end())
    {
        salida_decod<<(*i_decodificado);
        i_decodificado++;
    }
    salida_decod.close();
    return 0;
}
