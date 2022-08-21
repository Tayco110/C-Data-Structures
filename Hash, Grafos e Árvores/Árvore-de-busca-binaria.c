#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int entrada_limpa[MAX_SIZE];
int tamanho = 0;
int posicao = 0;
int flag_binary_tree = 1;

typedef struct binary_tree binary_tree;

struct binary_tree
{
	int item;
	binary_tree* left;
	binary_tree* right;
};

binary_tree* create_empty_binary_tree()
{
	return NULL;
}

binary_tree* create_small_binary_tree(int item,binary_tree* left,binary_tree* right)
{
	binary_tree* new_binary_tree = (binary_tree*)malloc(sizeof(binary_tree));
	
	new_binary_tree->item = item;
	new_binary_tree->left = left;
	new_binary_tree->right = right;

	return new_binary_tree;
}

binary_tree* create_big_binary_tree(binary_tree* bt)
{
	if(entrada_limpa[posicao] != -1)
	{
		bt = create_small_binary_tree(entrada_limpa[posicao],NULL,NULL);
		posicao++;
		bt->left = create_big_binary_tree(bt->left);
		bt->right = create_big_binary_tree(bt->right);
	}
	else
	{
		posicao++;
		return NULL;
	}
	return bt;
}

void limpar_entrada(char entrada[])
{
	char array_para_atoi[MAX_SIZE];
	int interno_para_atoi = 0;

	for(posicao=0;entrada[posicao] != '\0';posicao++)
	{
		if(entrada[posicao] != '(' && entrada[posicao] != ')' && entrada[posicao] != ' ')
		{
			while(entrada[posicao] != '(' && entrada[posicao] != ')' && entrada[posicao] != ' ')
			{
				array_para_atoi[interno_para_atoi] = entrada[posicao];
				interno_para_atoi++;
				posicao++;
			}
			array_para_atoi[interno_para_atoi] = '\0';
			entrada_limpa[tamanho] = atoi(array_para_atoi);
			interno_para_atoi = 0;
			tamanho++;
		}
		if(entrada[posicao] == '(' && entrada[posicao+1] == ')')
		{
			entrada_limpa[tamanho] = -1;
			tamanho++;
			posicao++;
		}
	}
}

void is_binary_tree(binary_tree* bt)
{
	if(bt->left != NULL)
	{
		if(bt->left->item > bt->item)
		{
			flag_binary_tree = 0;
			return;
		}
		else
		{
			is_binary_tree(bt->left);
		}
	}
	
	if(bt->right != NULL)
	{
		if(bt->right->item < bt->item)
		{
			flag_binary_tree = 0;
			return;
		}
		else
		{
			is_binary_tree(bt->right);
		}
	}
}

int main()
{
	char entrada[MAX_SIZE];
	gets(entrada);
	limpar_entrada(entrada);

	posicao = 0;

	binary_tree* arvore_binaria = create_empty_binary_tree();
	arvore_binaria = create_big_binary_tree(arvore_binaria);

	is_binary_tree(arvore_binaria);

	if(flag_binary_tree == 1)
	{
		printf("VERDADEIRO\n");
	}
	else
	{
		printf("FALSO\n");
	}
	return 0;
}