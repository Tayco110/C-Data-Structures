#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct list node;

struct list
{
	int item; 
	node *next;
};

node* create_linked_list()
{
	return NULL;
}

node* add(node *head, int item)
{
	node *new_node = (node*)malloc(sizeof(node));
	new_node->item = item;
	new_node->next = head;
	return new_node;
}

void print_linked_list(node *head)
{
	while (head != NULL) 
	{
		printf("%d ", head->item);
		head = head->next;
	}
	printf("\n");
}

node* remover(node *head)
{
	node *current = head;
	
	while(head->item == 0)
	{
		current = head;
		head = head->next;
		free(current);
	}
	return head;
}

void soma(node *numb1,node *numb2)
{
	int resto = 0, sum = 0;
	node *resultado = create_linked_list();

	while(1)
	{
		if((numb1 != NULL) && (numb2 != NULL))
		{
			if((numb1->item + numb2->item + resto) >= 10)
			{
				sum = ((numb1->item + numb2->item + resto)%10);
				resultado = add(resultado,sum);
				resto = 1;
				numb1 = numb1->next;
				numb2 = numb2->next;	
			}
			else
			{
				sum = (numb1->item + numb2->item);
				resultado = add(resultado,sum+resto);
				resto = 0;
				numb1 = numb1->next;
				numb2 = numb2->next;
			}
			
		}
		else if(numb1 == NULL)
		{
			if(numb2->item + resto >= 10)
			{
				sum = ((numb2->item + resto)%10);
				resultado = add(resultado,sum);
				resto = 1;
				numb2 = numb2->next;
			}
			else
			{
				resultado = add(resultado,numb2->item+resto);
				resto = 0;
				numb2 = numb2->next;
			}	
		}
		else if(numb2 == NULL)
		{
			if(numb1->item + resto >= 10)
			{
				sum = ((numb1->item + resto)%10);
				resultado = add(resultado,sum);
				resto = 1;
				numb1 = numb1->next;	
			}
			else
			{
				resultado = add(resultado,numb1->item+resto);
				resto = 0;
				numb1 = numb1->next;
			}	
		}
		if((numb1 == NULL) && (numb2 == NULL))
		{
			if(resto != 0)
			{
				resultado = add(resultado,resto);
				break;
			}
			else
			{
				break;
			}	
		}
	}
	resultado = remover(resultado);
	print_linked_list(resultado);
}

int main()
{
	node *list1 = create_linked_list();
	node *list2 = create_linked_list();
	node *list3 = create_linked_list();
	
	int valor;
	char proxChar;
	
	while(scanf("%d%c", &valor, &proxChar))
	{
		list1 = add(list1,valor);
		if(proxChar == '\n')
		{
		    break;
		}
	}
	getchar();

	while(scanf("%d%c", &valor, &proxChar))
	{
		list2 = add(list2,valor);
		if(proxChar == '\n')
		{
		    break;
		}
	}
	getchar();
    
    if(list1 == NULL && list2 == NULL)
    {
        printf("Lista vazia!\n");
    }
    else if(list1 == NULL)
    {
    	while(list2 != NULL)
    	{
    		list3 = add(list3,list2->item);
    		list2 = list2->next;
    	}
    	print_linked_list(list3);
    }
    else if(list2 == NULL)
    {
    	while(list1 != NULL)
    	{
    		list3 = add(list3,list1->item);
    		list1 = list1->next;
    	}
    	print_linked_list(list3);
    }
    else
    {
    	soma(list1,list2);
    }
	return 0;
}