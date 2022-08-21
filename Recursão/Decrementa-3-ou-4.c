#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int decremento(int valor)
{
    if((valor%10)!=valor)
    {
       return decremento(valor/10);
    }
    else
    {
        if((valor%10)%2==0)
       {
           return 2;
       }
       else
       {
           return 3;
       }
    }
}



int main() 
{
    int numero,flag;
    scanf("%d",&numero);
    flag = decremento(numero);
    if(flag==2)
    {
        numero -= 4;
    }
    else
    {
        numero -= 3;
    }
    printf("%d",numero);
	return 0;
}