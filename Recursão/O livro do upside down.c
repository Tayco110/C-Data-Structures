#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void upsd(char string[][1000], int controle) 
{
    if (controle == 0) 
    {
        printf("%s\n",string[controle]);
        return;
    } 
    else 
    {
        printf("%s\n",string[controle]);
        upsd(string, controle-1);
    }
}
 
int main() 
{
    int linhas = 0;
    char entrada[1000][1000];
    
    while (gets(entrada[linhas])) 
    {
        linhas++;
    }

    upsd(entrada, linhas-1);
 
    return 0;
}