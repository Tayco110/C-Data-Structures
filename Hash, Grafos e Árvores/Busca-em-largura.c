#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct adj_list adj_list;
typedef struct graph graph;
typedef struct queue queue;

struct adj_list
{
	int item;
	adj_list* next;	
};

struct graph
{
	adj_list** vertices;
	int* visited;
	int* dist;
	int* ant; 
	int size;
};

struct queue
{
	int max_size;
	int current_size;
	int head;
	int tail;
	int* items;
};

queue* create_queue(int size)
{
	queue* new_queue = (queue*)malloc(sizeof(queue));
	new_queue->max_size = (size*2);
	new_queue->current_size = 0;
	new_queue->head = 0;
	new_queue-> tail = new_queue->max_size-1;

	int* array = (int*)malloc((size*2)*sizeof(int));
	new_queue->items = array;

	return new_queue;
}

void enqueue(queue *queue, int item)
{
	queue->tail = (queue->tail + 1) % (queue->max_size);
	queue->items[queue->tail] = item;
	queue->current_size++;
}

int dequeue(queue *queue)
{
	int dequeued = queue->items[queue->head];
	queue->head = (queue->head + 1) % (queue->max_size);
	queue->current_size--;
	return dequeued;
}

int is_empty(queue* queue)
{
	if(queue->current_size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

graph* create_graph(int size)
{
	graph* new_graph = (graph*)malloc(sizeof(graph));
	adj_list** new_adj_list = (adj_list**)malloc(size*sizeof(adj_list*));
	
	int* visitados = (int*)malloc(size*sizeof(int));
	int* distancia = (int*)malloc(size*sizeof(int));
	int* anterior = (int*)malloc(size*sizeof(int)); 
	
	new_graph->vertices = new_adj_list;
	new_graph->visited = visitados;
	new_graph->dist = distancia;
	new_graph->ant = anterior;
	new_graph->size = size;
	
	int i;
	for(i=0;i<size;i++)
	{
		new_graph->vertices[i] = NULL;
		new_graph->visited[i] = 0;
		new_graph->dist[i] = (0-1);
		new_graph->ant[i] = (0-1);
	}

	return new_graph;
}

adj_list* create_adj_list(int item)
{
	adj_list* new_adj_list = (adj_list*)malloc(sizeof(adj_list));

	new_adj_list->item = item;
	new_adj_list->next = NULL;

	return new_adj_list;
}

void ordenar_adj_list(adj_list *head)
{
	adj_list *aux1=head;
	adj_list *aux2=head;
	
	int menor;
	
	while(aux1 != NULL)
	{
		while(aux2 != NULL)
		{
			if((aux2->item)<(aux1->item))
			{
				menor = aux2->item;
				aux2->item = aux1->item;
				aux1->item = menor;
			}
			aux2 = aux2->next;
		}
		aux1 = aux1->next;
		aux2 = aux1;
	}
}

void add_adge(graph* graph, int vertex1, int vertex2)
{
	adj_list* vertex = create_adj_list(vertex2);

	vertex->next = graph->vertices[vertex1];
	graph->vertices[vertex1] = vertex;
}

void ordenar_graph(graph* graph,int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		ordenar_adj_list(graph->vertices[i]);
	}
}

void bfs(graph* graph, int source)
{
	queue* aux_queue = create_queue(graph->size);
	int dequeued;
	
	adj_list* aux_adj_list = graph->vertices[source];
	
	printf("Iniciando busca em largura a partir de %d\n",source);
	graph->visited[source] = 1;
	graph->dist[source] = 0;
	
	enqueue(aux_queue,source);

	while(!is_empty(aux_queue))
	{
		dequeued = dequeue(aux_queue);
		aux_adj_list = graph->vertices[dequeued];

		while(aux_adj_list != NULL)
		{
			if(!graph->visited[aux_adj_list->item])
			{
				printf("Iniciando busca em largura a partir de %d\n",aux_adj_list->item);
				graph->visited[aux_adj_list->item] = 1;
				enqueue(aux_queue,aux_adj_list->item);
				
				if(graph->dist[aux_adj_list->item] == -1)
				{
					graph->dist[aux_adj_list->item] = (graph->dist[dequeued] + 1);
					graph->ant[aux_adj_list->item] = dequeued;	
				}
			}
			aux_adj_list = aux_adj_list->next;
		}
	}
}

void distancia(graph* graph)
{
	int i;

	for(i=0;i<graph->size;i++)
	{
		if(graph->dist[i] == -1)
		{
			printf("%d | - | -\n",i);
		}
		else
		{
			if(graph->dist[i] == 0)
			{
				printf("%d | %d | -\n",i,graph->dist[i]);
			}
			else
			{
				printf("%d | %d | %d\n",i,graph->dist[i],graph->ant[i]);
			}
		}
	}
}

void caminho(graph* graph, int vertex1, int vertex2,int input)
{
	if(graph->ant[vertex2] == -1 && vertex1 != vertex2)
	{
		printf("Sem caminho entre %d e %d",vertex1,vertex2);
	}
	else
	{
		if(vertex1 == vertex2)
		{
			printf("Caminho entre %d e %d: %d",vertex1,input,vertex2);
			return;
		}
		else
		{
			caminho(graph,vertex1,graph->ant[vertex2],input);
			printf(" => %d",vertex2);
		}
	}
	
}

void reset(graph* graph,int size)
{
	int i;

	for(i=0;i<size;i++)
	{
		graph->visited[i] = 0;
		graph->dist[i] = (0-1);
		graph->ant[i] = (0-1);
	}
}

int main() 
{

	int vertices, arestas, testes;
	int aresta1, aresta2;
	int controle;
	
	scanf("%d %d %d",&vertices,&arestas,&testes);

	graph* grafo = create_graph(vertices);

	for(controle=0;controle<arestas;controle++)
	{
		scanf("%d %d",&aresta1,&aresta2);
		add_adge(grafo,aresta1,aresta2);
	}
	ordenar_graph(grafo,vertices);

	for(controle=0;controle<testes;controle++)
	{
		scanf("%d %d",&aresta1,&aresta2);
		printf("--------\n");
		printf("\n");
		printf("Caso de Teste #%d - BFS(%d)\n",controle+1,aresta1);
		printf("\n");
		bfs(grafo,aresta1);
		printf("\n");
		distancia(grafo);
		printf("\n");
		caminho(grafo,aresta1,aresta2,aresta2);
		printf("\n");
		printf("\n");
		reset(grafo,vertices);
	}
	printf("--------\n");
	
	return 0;
}