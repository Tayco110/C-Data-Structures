#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void decript(int tam,int cont,char m[])
{
    if(cont==tam)
    {
        if(m[cont-1]=='*')
        {
            printf("(%d)",cont);
            return;
        }
        if(m[cont-1]=='-')
        {
            printf("%d",cont);
            return;
        }
    }
    else
    {
        if(m[cont-1]=='*')
        {
            printf("(%d",cont);
            decript(tam,cont+1,m);
            printf(")");
        }
        else
        {
            printf("%d",cont);
            decript(tam,cont+1,m);
        }
    }
}


int main() 
{
    int tamanho,controle=1;
    char mensagem[101];
    fgets(mensagem,101,stdin);
    tamanho = strlen(mensagem);
    decript(tamanho,controle,mensagem);
	return 0;
}