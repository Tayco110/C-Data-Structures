#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int rick(int n,int t)
{
    if(t==0)
    {
        return n;
    }
    else
    {
        if(t%2==0)
        {
            return rick(n,t-1)+rick(n,t-1)%5;
        }
        else
        {
            return rick(n,t-1)+3;
        }
    }
}



int main() 
{
    int n,t;
    scanf("%d" "%d",&n,&t);
    printf("%d",rick(n,t));
	return 0;
}