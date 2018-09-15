int divisibles(int modulo)
{
	int temp;
	long long int aux=0;
	int dv2=0,dv3=0,dv5=0,dv7=0,dv11=0,dv13=0,dv17=0;

	if(modulo=2)
	{
		ifstream entrada("propiedad2.txt");
	}

		while(entrada>>temp)
		{
//			cout<<" modulo "<<modulo<<" temp "<<temp<<" temp%modulo "<<(temp%modulo)<<endl;
			if(temp%modulo==0)
				{aux++;}
		}
		entrada.close();
//		cout<<"Sali del while 2"<<endl;
		return aux;
}
	
	else if(modulo=3)
		{
			ifstream entrada("propiedad2.txt");

			while(entrada>>temp)
			{
//				cout<<" modulo "<<modulo<<" temp "<<temp<<" temp%modulo "<<(temp%modulo)<<endl;
				if(temp%modulo==0)
					{dv3++;}
			}
//		cout<<"Sali del while 3"<<endl;
		entrada.close();
		return dv3;
		}
	else if(modulo=5)
		{
			ifstream entrada("propiedad5.txt");

			while(entrada>>temp)
			{
				if(temp%modulo==0)					
					{dv5++;}
			}
		entrada.close();
		return dv5;
		}
	else if(modulo=7)
		{
			ifstream entrada("propiedad7.txt");

			while(entrada>>temp)
			{
				if(temp%modulo==0)
					{dv7++;}
			}
		entrada.close();
		return dv7;
		}
	else if(modulo=11)
		{
			ifstream entrada("propiedad11.txt");

			while(entrada>>temp)
			{
				if(temp%modulo!=0)
					{dv11++;}
			}
		entrada.close();
		return dv11;
		}
	else if(modulo=13)
		{
			ifstream entrada("propiedad13.txt");

			while(entrada>>temp)
			{
				if(temp%modulo!=0)
					{dv13++;}
			}
		
		entrada.close();
		return dv13;
		}
	else if(modulo=17)
		{
			ifstream entrada("propiedad17.txt");

			while(entrada>>temp)
			{
				if(temp%modulo!=0)
					{dv17++;}
			}
		entrada.close();
		return dv17;
		}
}