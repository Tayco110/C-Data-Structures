#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

int entrada_limpa[MAX_SIZE];
int tamanho = 0;
int posicao = 0;
int flag_para_target = 0;
int flag_for_depth = INT_MAX;
int counter_for_depthness = 0;

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

void search_node(binary_tree* bt, int target)
{
	if(bt != NULL)
	{
		if(bt->item == target)
		{
			flag_para_target = 1;
		}
		else
		{	
			search_node(bt->left,target);
			search_node(bt->right,target);
		}
	}
}

void dephtness(binary_tree* bt, int target)
{
	if(bt->item == target)
	{
		if(counter_for_depthness < flag_for_depth)
		{
			flag_for_depth = counter_for_depthness;
		}
		return;
	}
	else
	{
		if(bt->left != NULL)
		{
			counter_for_depthness++;
			dephtness(bt->left,target);
			counter_for_depthness--;
		}
		if(bt->right != NULL)
		{
			counter_for_depthness++;
			dephtness(bt->right,target);
			counter_for_depthness--;
		}
	}
}

int main()
{
	char entrada[MAX_SIZE];
	int target;
	
	gets(entrada);
	scanf("%d",&target);
	
	limpar_entrada(entrada);
	posicao = 0;
	
	binary_tree* arvore_binaria = create_empty_binary_tree();
	arvore_binaria = create_big_binary_tree(arvore_binaria);

	search_node(arvore_binaria,target);

	if(flag_para_target == 1)
	{
		printf("ESTA NA ARVORE\n");
		dephtness(arvore_binaria,target);
		printf("%d\n",flag_for_depth);
	}
	else
	{
		printf("NAO ESTA NA ARVORE\n");
		printf("-1\n");
	}

	return 0;
}