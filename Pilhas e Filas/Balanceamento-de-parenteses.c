#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 256

typedef struct stack stack;

struct stack 
{
	int current_size;
	char items[MAX_STACK_SIZE];
};

stack* create_stack()
{
	stack *new_stack = (stack*) malloc(sizeof(stack));
	new_stack->current_size = 0;
	return new_stack;
}

void push(stack *stack, char item)
{
	if (stack->current_size == MAX_STACK_SIZE) 
	{
		printf("Stack overflow");
	} 
	else 
	{
		stack->items[stack->current_size] = item;
		stack->current_size++;
	}
}

char pop(stack *stack)
{
	if (stack->current_size == 0) 
	{
		printf("Stack underflow");
		return;
	} 
	else 
	{
		return stack->items[--stack->current_size];
	}
}




int main() 
{
	int controle,programa,interno;
	
	scanf("%d\n",&controle);

	for(programa=0;programa<controle;programa++)
	{
		stack *pilha = create_stack();
		int tamanho;
		char ds;
		char string[MAX_STACK_SIZE];
		
		if(strcmp(fgets(string,MAX_STACK_SIZE,stdin),"\n") != 0)
		{
			tamanho = strlen(string);
		
			for(interno=0;interno<tamanho;interno++)
			{
				if(string[interno]=='(' || string[interno]=='[')
				{
					push(pilha,string[interno]);
				}
				
				if(string[interno]==')')
				{
					
					if(pilha->current_size==0)
					{
						printf("No\n");
						break;
					}
					ds = pop(pilha);
					if(ds != '(')
					{
						printf("No\n");
						break;
					}
				}
				
				else if(string[interno]==']')
				{
					
					if(pilha->current_size==0)
					{
						printf("No\n");
						break;
					}
					ds = pop(pilha);
					if(ds != '[')
					{
						printf("No\n");
						break;
					}
				}

				if(interno == tamanho-1 && pilha->current_size == 0)
				{
					printf("Yes\n");	
				}
				else if(interno == tamanho-1 && pilha->current_size!=0)
				{
					printf("No\n");	
				}
			}
		}
		else
		{
			printf("Yes\n");	
		}
		
	}


	return 0;
}