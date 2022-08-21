#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int posicao(char letra)
{
	int posicao;
	posicao = letra;
	return posicao-65;
}


int main() 
{
	int casos,controle,linhas,interno;
	scanf("%d",&casos);

	for(controle=0;controle<casos;controle++)
	{
		scanf("%d",&linhas);
		int chave = 0; 
		
		for(interno=0;interno<linhas;interno++)
		{
			char string_L[51];
			scanf("%s",string_L);

			int i,tamanho = strlen(string_L);


			for(i=0;i<tamanho;i++)
			{
				chave += posicao(string_L[i])+i+interno;
			}	
		}
		printf("%d\n",chave);
		chave = 0;
	}	
	return 0;
}