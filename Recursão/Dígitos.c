#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int willy(int valor,int bandeira)
{
    int atual=valor%10;
    if(valor==0)
    {
        return atual;
    }
    else
    {
        if(atual%2==0)
        {
            return (atual*2*bandeira)+willy(valor/10,bandeira+1);
        }
        else
        {
            return (atual*3*bandeira)+willy(valor/10,bandeira+1);
        }        
    }
}
int main() 
{
    int a,flag=1;
    scanf("%d",&a);
    while(a!=0)
    {
        printf("%d\n",willy(a,flag));
        scanf("%d",&a);
    }
	return 0;
}