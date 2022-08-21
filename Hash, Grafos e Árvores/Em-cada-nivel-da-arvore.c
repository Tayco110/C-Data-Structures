#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int nivel = 1;
int nivel_mais_baixo = INT_MIN;

int maior_do_nivel = INT_MIN;
int menor_do_nivel = INT_MAX;

typedef struct binary_tree binary_tree;
typedef struct hash hash;

struct binary_tree
{
	int name;
	int item;
	binary_tree* left;
	binary_tree* right;
};

struct hash
{
	int size;
	int* conteudo;
	int* left;
	int* right;
};

hash* create_hash(int size)
{
	hash* new_hash = (hash*)malloc(sizeof(hash));

	int* conteudo = (int*)malloc(size*sizeof(int));
	int* left = (int*)malloc(size*sizeof(int));
	int* right = (int*)malloc(size*sizeof(int));

	new_hash->conteudo = conteudo;
	new_hash->left = left;
	new_hash->right = right;

	new_hash->size = size;

	int i;

	for(i=0;i<size;i++)
	{
		new_hash->conteudo[i] = -1;
		new_hash->left[i] = -1;
		new_hash->right[i] = -1;
	}

	return new_hash;
}

void add_hash(hash* ht,int chave,int item, int esquerda, int direita)
{
	ht->conteudo[chave] = item;
	ht->left[chave] = esquerda;
	ht->right[chave] = direita;
}

binary_tree* create_small_binary_tree(int name,int item,binary_tree* left,binary_tree* right)
{
	binary_tree* new_binary_tree = (binary_tree*)malloc(sizeof(binary_tree));
	
	new_binary_tree->item = item;
	new_binary_tree->name = name;
	new_binary_tree->left = left;
	new_binary_tree->right = right;

	return new_binary_tree;
}

binary_tree* create_big_binary_tree(binary_tree* bt,hash* ht)
{
	if(ht->left[bt->name] != -1)
	{
		bt->left = create_small_binary_tree(ht->left[bt->name],ht->conteudo[ht->left[bt->name]],NULL,NULL);
		bt->left = create_big_binary_tree(bt->left,ht);
	}
	if(ht->right[bt->name] != -1)
	{
		bt->right = create_small_binary_tree(ht->right[bt->name],ht->conteudo[ht->right[bt->name]],NULL,NULL);
		bt->right = create_big_binary_tree(bt->right,ht);
	}
	return bt;
}

void contador_de_niveis(binary_tree* bt)
{
	if(nivel > nivel_mais_baixo)
	{
		nivel_mais_baixo = nivel;
	}
	if(bt->left != NULL)
	{
		nivel++;
		contador_de_niveis(bt->left);
		nivel--;
	}
	if(bt->right !=NULL)
	{
		nivel++;
		contador_de_niveis(bt->right);
		nivel--;
	}
}

void procurar_menor_do_nivel(binary_tree* bt, int nivel_target)
{
	if(nivel == nivel_target)
	{
		if(bt->item < menor_do_nivel)
		{
			menor_do_nivel = bt->item;
		}
	}
	if(bt->left != NULL)
	{
		nivel++;
		procurar_menor_do_nivel(bt->left,nivel_target);
		nivel--;
	}
	if(bt->right != NULL)
	{
		nivel++;
		procurar_menor_do_nivel(bt->right,nivel_target);
		nivel--;
	}
}

void procurar_maior_do_nivel(binary_tree* bt, int nivel_target)
{
	if(nivel == nivel_target)
	{
		if(bt->item > maior_do_nivel)
		{
			maior_do_nivel = bt->item;
		}
	}
	if(bt->left != NULL)
	{
		nivel++;
		procurar_maior_do_nivel(bt->left,nivel_target);
		nivel--;
	}
	if(bt->right != NULL)
	{	
		nivel++;
		procurar_maior_do_nivel(bt->right,nivel_target);
		nivel--;
	}
}

int main()
{
	int numero_de_entradas, controle;
	int item,esquerda,direita;

	scanf("%d",&numero_de_entradas);

	hash* tabela_hash = create_hash(numero_de_entradas);

	for(controle=0;controle<numero_de_entradas;controle++)
	{
		scanf("%d %d %d",&item,&esquerda,&direita);
		add_hash(tabela_hash,controle,item,esquerda,direita);
	}

	binary_tree* arvore_binaria = create_small_binary_tree(0,tabela_hash->conteudo[0],NULL,NULL);
	arvore_binaria = create_big_binary_tree(arvore_binaria,tabela_hash);

	contador_de_niveis(arvore_binaria);
	nivel = 1;

	int nivel_target;

	for(nivel_target=1;nivel_target<=nivel_mais_baixo;nivel_target++)
	{
		procurar_maior_do_nivel(arvore_binaria,nivel_target);
		nivel = 1;
		procurar_menor_do_nivel(arvore_binaria,nivel_target);
		nivel = 1;
		
		printf("Nivel %d: Maior = %d, Menor = %d\n",nivel_target,maior_do_nivel,menor_do_nivel);

		maior_do_nivel = INT_MIN;
		menor_do_nivel = INT_MAX;
	}

	return 0;
}