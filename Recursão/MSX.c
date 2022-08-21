#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	char *v, parada[8]="the end!";
	int i,tamanho;

	v = (char*)malloc(75*sizeof(char));
	
	while(1)
	{
		fgets(v,75,stdin);
		if(strncmp(v,parada,8)==0)
		{
			break;
		}
		else
		{
			tamanho = strlen(v);
			for(i=0;i<tamanho;i++)
			{
				printf("%c",(char*)toupper(v[i]));
			}
			v=(char*)realloc(v,75*sizeof(char));
		}
	}
	free(v);
	return 0;
}
