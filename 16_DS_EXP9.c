// Write a C program to perform Depth First Search (DFS) traversal on a graph.

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int vertex;
    struct node* next;
} *GNODE;

GNODE graph[101];   
int visited[101];   

void DFS(int v) {
    GNODE temp;
    visited[v] = 1;
    printf("\n%d", v);
    for (temp = graph[v]; temp != NULL; temp = temp->next) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
    }
}
void main() {
    int n,E,i,s,d,v;
    GNODE q,p;
    printf("Enter no of vertices: ");
	scanf("%d",&n);
	printf("Enter no of edges: ");
	scanf("%d",&E);
	for(i=1;i<=E;i++) {
		printf("Enter source: ");
		scanf("%d",&s);
		printf("Enter destination: ");
		scanf("%d",&d);
		q=(GNODE)malloc(sizeof(struct node));
    	q->vertex=d;
    	q->next=NULL;
    	if(graph[s]==NULL)
        	graph[s]=q;
        else {
        	p=graph[s];
        	while(p->next!=NULL)
            	p=p->next;
    		p->next=q;
    	}
	}
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter Start Vertex for DFS: ");
    scanf("%d", &v);
    printf("DFS of graph: ");
    DFS(v);
    printf("\n");
}