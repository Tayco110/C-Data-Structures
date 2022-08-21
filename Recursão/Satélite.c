#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void satelite(int t,char a[][256])
{
	int linha,coluna,ctrlinha,ctrcoluna,auxlinha,auxcoluna;
	char aux[256][256];

	for(linha=0;linha<t;linha++)
	{
		for(coluna=0;coluna<t;coluna++)
		{
			if(a[linha][coluna]=='*')
			{
				ctrlinha=linha;
				ctrcoluna=coluna;	
			}
		}
	}

	if(t==1)
	{
		printf("0");
		return;
	}
	else
	{
		if((ctrlinha<t/2)&&(ctrcoluna>=t/2))//quadrante 1
		{
			for(linha=0,auxlinha=0;linha<t/2,auxlinha<t/2;linha++,auxlinha++)
			{
				for(coluna=t/2,auxcoluna=0;coluna<t,auxcoluna<t/2;coluna++,auxcoluna++)
				{
					aux[auxlinha][auxcoluna]=a[linha][coluna];
				}
			}
			printf("1");
			satelite(t/2,aux);
		}
		else if((ctrlinha<t/2)&&(ctrcoluna<t/2))//quadrante 2
		{
			for(linha=0,auxlinha=0;linha<t/2,auxlinha<t/2;linha++,auxlinha++)
			{
				for(coluna=0,auxcoluna=0;coluna<t/2,auxcoluna<t/2;coluna++,auxcoluna++)
				{
					aux[auxlinha][auxcoluna]=a[linha][coluna];
				}
			}
			printf("2");
			satelite(t/2,aux);
		}
		else if((ctrlinha>=t/2)&&(ctrcoluna<t/2))//quadrante 3
		{
			for(linha=t/2,auxlinha=0;linha<t,auxlinha<t/2;linha++,auxlinha++)
			{
				for(coluna=0,auxcoluna=0;coluna<t/2,auxcoluna<t/2;coluna++,auxcoluna++)
				{
					aux[auxlinha][auxcoluna]=a[linha][coluna];
				}
			}
			printf("3");
			satelite(t/2,aux);
		}
		else if((ctrlinha>=t/2)&&(ctrcoluna>=t/2))//quadrante 4
		{
			for(linha=t/2,auxlinha=0;linha<t,auxlinha<t/2;linha++,auxlinha++)
			{
				for(coluna=t/2,auxcoluna=0;coluna<t,auxcoluna<t/2;coluna++,auxcoluna++)
				{
					aux[auxlinha][auxcoluna]=a[linha][coluna];
				}
			}
			printf("4");
			satelite(t/2,aux);
		}	
	}
}

int main()
{
	int t,i,j;
    scanf("%d",&t);
    char objetos[256][256];
    for(i=0;i<t;i++)
    {
       scanf("%s",&objetos[i]);
    }
    satelite(t,objetos);
	return 0;
}