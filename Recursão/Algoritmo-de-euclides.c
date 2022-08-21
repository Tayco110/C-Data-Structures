#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int a,int b)
{
    if(a%b==0)
    {
        return b;
    }
    else
    {
        mdc(b,(a%b));
    }
}



int main() 
{
    int n1,n2,casos;
    scanf("%d",&casos);
    scanf("%d" "%d",&n1,&n2);
    while(casos!=0)
    {
        printf("MDC(%d,%d) = %d\n",n1,n2,mdc(n1,n2));
        scanf("%d" "%d",&n1,&n2);
        casos--;
    }
	return 0;
}