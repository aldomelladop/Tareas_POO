
bool BigInteger::esChar()const
{
	bool control=true;

	int n=VectorToInt(entero);

    if(n<(numeric_limits<char>::max()))
    {
	   	if(n>(numeric_limits<char>::min()))
	   	{
	       	return control=true;
	   	}
    }
    else
    	{
    		return control=false;
    	}
return control;
}


bool BigInteger::esShortInt()const
{
    bool control=true;

    int n=VectorToInt(entero);

    if(n<(numeric_limits<short int>::max()))
    {
        if(n>(numeric_limits<short int>::min()))
        {
            return control=true;
        }
    }
    else
        {
            return control=false;
        }
return control;
}

bool BigInteger::esLongInt()const
{
    bool control=true;

    int n=VectorToInt(entero);

    if(n>(numeric_limits<long int>::min()))
    {
        if(n>(numeric_limits<long int>::max()))
        {
            return control=false;
        }
    }
    else
        {
            return control=true;
        }
return control;
}


bool BigInteger::esLongLongInt()const
{
    bool control=true;

    int n=VectorToInt(entero);

    if(n<(numeric_limits<long long int>::max()))
    {
        if(n>(numeric_limits<long long int>::min()))
        {
            return control=true;
        }
    }
    else
        {
            return control=false;
        }
return control;
}


int BigInteger::cmp(BigInteger& q)const;
{
    int comparador,signo1,signo2,largo1,largo2;
    vecint num1,num2;

    //Datos del objeto BigInteger con el cual se comparara
    
    num1 = entero;
    largo1 = num1.size(); 
    signo1 = s;

    //numero respecto del cual se hace la comparacion
    /* size(); es usado para vectores, mapas, listas, etc
     length(); es usado para strings*/

    BigInteger aux(b);
    num2   = aux.getEntero();
    largo2 = num2.size(); 
    signo2 = aux.getSigno();



    if (signo1>signo2)
    {
        if(largo1>largo2)
        {
            comparador = 1;    
        }
        else
        {
            comparador = -1;
        }
    }
    else if (signo1<signo2)
    {
        if(largo1<largo2)
        {
            comparador = 1;    
        }
        else
        {
            comparador = -1;
        }
    }
    else
    {
        comparador = 0;   
    }   
    return comparador;
}

iterador it1=num1.begin();
iterador it2=num2.begin();

for(it1;it1!=num1.end();it1++)
{
    if(*it1>*it2)
    {
        
    }
}