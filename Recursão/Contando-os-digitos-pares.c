#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int contador(int valor)
{
    int atual=valor%10,counter;
    if(valor==0)
    {
        return 0;
    }
    else
    {
        if(atual%2==0)
        {
            return contador(valor/10)+1;
        }
        else
        {
            return contador(valor/10);
        }
    }
}

int main() 
{
    int a;
    scanf("%d",&a);
    printf("%d",contador(a));
	return 0;
}