#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


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

int is_empty(binary_tree* arvore)
{
	if(arvore == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

binary_tree* create_binary_tree(int valor)
{
	binary_tree* new_binary_tree = (binary_tree*)malloc(sizeof(binary_tree));

	new_binary_tree->item = valor;
	new_binary_tree->left = NULL;
	new_binary_tree->right = NULL;

	return new_binary_tree;
}

void print_pre_order(binary_tree* bt)
{
	if(!is_empty(bt))
	{
		printf(" ( %d ", bt->item);
        print_pre_order(bt->left);
        print_pre_order(bt->right);
        printf(") ");
	}
	else
	{
	    printf(" () ");
	}

}

binary_tree* add_binary_tree(binary_tree* arvore, int item)
{
	int aux;
	

	if(arvore == NULL)
	{
		arvore = create_binary_tree(item);
	}
	else
	{
		aux = arvore->item;

		if(item < aux)
		{
			arvore->left = add_binary_tree(arvore->left,item);
		}
		else
		{
			arvore->right = add_binary_tree(arvore->right,item);
		}
	}
	return arvore; 
}

int main()
{
	int valor;
	char ProxChar;

	binary_tree* arvore = create_empty_binary_tree();


	while(scanf("%d",&valor) != EOF)
	{
	    printf("----\n");
	    printf("Adicionando %d\n  ",valor);
		arvore = add_binary_tree(arvore,valor);
		print_pre_order(arvore);
		printf("\n");
	}
	printf("----");
	return 0;
}