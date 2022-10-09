#include<stdio.h>
#include<stdlib.h>



typedef struct listnode// queue node
{
	int data;
	struct listnode* next;
}listnode;

typedef struct list//queue
{
	listnode *head;
}list;

typedef struct graph
{
	int vertices;
	list* array;
}graph;

int visited[1000];

graph* creategraph(int n)//functio for creating graph
{
	int i;
	graph* G=(graph *)(malloc(sizeof(graph)));//alloting memory to one instance of graph G
	G->vertices = n;
	
	G->array = (list *)malloc(n * sizeof(struct list));
	
	for(i=0; i<n; i++)
		G->array[i].head = NULL;//pointing every vertex to null
	return G;
}

void addedge(graph* G, int src, int dest)
{
	listnode* newnode;//creating new node of Qnode
	newnode=(listnode *)(malloc(sizeof(listnode)));
	newnode->data=dest;
	newnode->next=G->array[src].head;//creating edge between new node and previous node
	G->array[src].head=newnode;
}

void traverse(graph* G, int n)
{
	graph* temp=G;
	int i;
	list* temp_list;
	listnode* temp_node;
	for(i=0; i<n; i++)
	{
		temp_node=temp->array[i].head;//given the root node giving vetex of the node 
		while(temp_node!=NULL)
		{
			printf("%d -> %d\t", i, temp_node->data);
			temp_node=temp_node->next;//printing the node and moving temp-node to next
		}
		printf("\n");
	}
	return;
}

void dfs(graph* G, int v)
{
	int i, j;
	printf("%d ", v);
	visited[v]=1;
	listnode* temp_node=G->array[v].head;
	while(temp_node!=NULL)
	{
		if(!visited[temp_node->data])//run while temp-node->data is not visited
		{
			//Uncomment the line below to understand the DFS traversal
			//printf("\tMoving from %d to %d", v, temp_node->data);nline;
			dfs(G,temp_node->data);//recursion of dfs
		}
			
		temp_node=temp_node->next;//move on to next 
	}
	return;
}

int main()
{
	int n, i, j, k, temp, m, a, b;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	printf("Enter the number of edges : ");
	scanf("%d", &m);
	printf("Enter the edges : "); printf("\n");
	int ini=n+1;
	graph* G=creategraph(n+1);//creating graph
	for(i=0;i<m;i++)
	{
		scanf("%d", &a); scanf("%d", &b);
		addedge(G,a,b);
		if(a<ini)//ini is the starting vertex,as a will always < no. of edges
			ini=a;
	}
	printf("Traversing the adjacency list : ");
	printf("\n");
	traverse(G,n);//writing adj list in depth
	printf("\n");

	printf("DFS traversal starting with %d : ", ini);printf("\n");
	dfs(G,ini);
	printf("\n");
	return 0;
}


