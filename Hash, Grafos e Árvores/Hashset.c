#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node node;
typedef struct hash_table hash_table;

struct node
{
	long int value;
	node* next;	
};

struct hash_table
{
	node** table;
};

hash_table* creat_hash_table(long int m)
{
	hash_table* new_hash = (hash_table*)malloc(sizeof(hash_table));
	
	node** new_table = (node**)malloc(m*sizeof(node*));
	new_hash->table = new_table;

	long int i;
	for(i=0;i<m;i++)
	{
		new_hash->table[i] = NULL;
	}

	return new_hash;
}

long int calc_hash(long int k,long int m)
{
	return (k%m);
}

node* add_head(node* head, long int value)
{
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	new_node->next = head;

	return new_node;
}

long int search(node* head, long int value)
{
	node* aux = head;
	long int flag = 0;

	while(aux != NULL)
	{
		if((aux->value)==(value))
		{
			flag = 1;
		}
		aux = aux->next; 
	}

	return flag;
}

long int comparacoes(node* head, long int value)
{
	node* aux = head;
	long int contador = 0;

	while(aux != NULL)
	{
		if((aux->value)==(value))
		{
			contador++;
			return contador;
		}
		else
		{
			contador++;
		}
		aux = aux->next;
	}

	return contador;
}

long int put(hash_table* ht, long int key, long int value)
{
	if(ht->table[key] == NULL)
	{
		ht->table[key] = add_head(ht->table[key],value);
		return 1;
	}
	else
	{
		if(search(ht->table[key],value) == 0)
		{
			ht->table[key] = add_head(ht->table[key],value);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

node* remove_node(node* head, long int value)
{
	node* current = head;
	node* previous = NULL;

	while(current != NULL && current->value != value)
	{
		previous = current;
		current = current->next;
	}
	if(current == NULL)
	{
		return head;
	}
	if(previous == NULL)
	{
		head = current->next;
	}
	else
	{
		previous->next = current->next;
	}
	
	free(current);
	return head;
}

long int remove_item(hash_table* ht,long int key,long int value)
{
	if(ht->table[key] == NULL)
	{
		return 0;
	}
	else if(search(ht->table[key],value) == 0)
	{
		return 0;
	}
	else if(search(ht->table[key],value) == 1)
	{
		ht->table[key] = remove_node(ht->table[key],value);
		return 1;
	}
}

hash_table* rerashing(hash_table* hs, long int m)
{
	long int new_m = ((m*2)-1),new_k;

	hash_table* rerashing = creat_hash_table(new_m);

	node* aux;

	long int i;
	for(i=0;i<m;i++)
	{
		aux = hs->table[i];
		while(aux != NULL)
		{
			new_k = calc_hash(aux->value,new_m);
			put(rerashing,new_k,aux->value);
			aux = aux->next;
		}	
	}

	return rerashing;
}
long int counter(node* head)
{
	node* aux = head;
	long int contador = 0;

	while(aux != NULL)
	{
		contador++;
		aux = aux->next;
	}

	return contador;
}

long int cardinality(hash_table* ht,long int m)
{
	long int acumulador = 0;

	long int i;

	for(i=0;i<m;i++)
	{
		acumulador += counter(ht->table[i]);
	}

	return acumulador;

}

long int maior_lista(hash_table* ht,long int m)
{
	long int biggest = 0;
	long int controle;

	long int i;
	for(i=0;i<m;i++)
	{
		controle = counter(ht->table[i]);
		if(controle > biggest)
		{
			biggest = controle;
		}
	}

	return biggest;
}

double carry_factor(hash_table* ht, double m)
{
	long int i;
	double carry_factor,contador;
	
	contador = cardinality(ht,m);

	carry_factor = (contador/m);
	return carry_factor;
}
int main()
{
	long int k,m=7,w=0,chave,odd;
	char comando[5];

	hash_table* tabela_hash = creat_hash_table(m);

	while(scanf("%s",comando) != EOF)
	{
		if(strcmp(comando,"ADD") == 0)
		{
			scanf("%ld",&k);
			chave = calc_hash(k,m);
			odd = comparacoes(tabela_hash->table[chave],k);
			printf("%ld ",w);
			printf("%ld ",put(tabela_hash,chave,k));
			printf("%ld\n",odd);
			if(carry_factor(tabela_hash,m) >= 0.75)
			{
				tabela_hash = rerashing(tabela_hash,m);
				m = ((m*2)-1);
			}
			w++;
		}
		else if(strcmp(comando,"DEL") == 0)
		{
			scanf("%ld",&k);
			chave = calc_hash(k,m);
			odd = comparacoes(tabela_hash->table[chave],k);
			printf("%ld ",w);
			printf("%ld ",remove_item(tabela_hash,chave,k));
			printf("%ld\n",odd);
			w++;
		}
		else if(strcmp(comando,"HAS") == 0)
		{
			scanf("%ld",&k);
			chave = calc_hash(k,m);
			odd = comparacoes(tabela_hash->table[chave],k);
			printf("%ld ",w);
			printf("%ld ",search(tabela_hash->table[chave],k));
			printf("%ld\n",odd);
			w++;
		}
		else if(strcmp(comando,"PRT") == 0)
		{
			printf("%ld ",w);
			printf("%ld ",m);
			printf("%ld ",cardinality(tabela_hash,m));
			printf("%ld\n",maior_lista(tabela_hash,m));
			w++;
		}
	}
	return 0;
}