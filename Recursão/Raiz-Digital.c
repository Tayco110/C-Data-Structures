#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int raiz(int resultado)
{
    if(resultado<10)
    {
        return resultado;
    }
    else
    {
        return raiz(resultado/10+resultado%10);
    }
}
int main() 
{
    int inteirox,indicek,interacoesn,controle=0,contador=0,i;
    scanf("%d",&interacoesn);
    for(i=0;i<interacoesn;i++)
    {
        scanf("%d" "%d",&indicek,&inteirox);
        while(1)
        {
            if(raiz(controle)==inteirox)
            {
                contador++;
            }
            if(contador==indicek)
            {
                printf("%d\n",controle);
                controle = 0;
                contador = 0;
                break;
            }
            controle++;
        }
    }
	return 0;
}