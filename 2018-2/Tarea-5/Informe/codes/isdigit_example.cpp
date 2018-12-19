/*
	while(*it1!='.')
	{
		k  = int(*it1-48);

		if(it1==input.begin() && k==0)
		{
			sign = ' ';
			signo = 1;
			entero.push_back(k);	
		}
		else if(it1==input.begin() && k!=0 && *it1=='-')
		{
			sign = *it1;
			signo = *it1;
		}
		else
		{
			sign = ' ';
			signo = 1;
			entero.push_back(k);
		}
		numero.push_back(k);
		it1++;
	}

	for(auto x:input)
	{
		cout<<"x: "<<x<<endl;

		k  = int(x-48);

		if(x=='-' && j!=0)
		{
			signo = -1;
			sign  = '-';
		}
		else if(k==0 && j==0)
		{
			signo = 1;
			sign = '0';
			entero.push_back(k);
		}
		else
		{
			signo = 1;
			sign = '+';
			entero.push_back(k);
		}
			numero.push_back(k);
		j++;
	}
*/

/* isdigit example */

for(it1;it1!=input.end();it1++)
{
	k  = int(*it1-48);

	if(j==0)
	{
		if(*it1=='0')
		{
			signo = 0;
			entero.push_back(0);
		}
		else if(*it1=='-')
		{
			signo=-1;
		}
	}
	do
	{
		cout<<"Entro al else"<<endl;
		signo = 1;
		entero.push_back(k);
	}
	while(isdigit(k));

	numero.push_back(k);
	j++;
}

int flag = 1;

while(flag!=0)
{
	k  = int(*it1-48);

	if(j==0)
	{
		if(*it1=='0')
		{
			signo = 0;
			entero.push_back(0);
		}
		else if(*it1=='-')
		{
			signo=-1;
		}
	}
	else if(*it1=='.')
	{
		cout<<"flag cambiada"<<endl;
		flag=0;
	}
	else
	{
		cout<<"\nEntro al else"<<endl;
		signo = 1;
		entero.push_back(k);
	}
	numero.push_back(k);
	it1++;
}