// Write a C program to perform Breadth First Search (BFS) traversal on a graph.

#include <stdio.h>
#include <stdlib.h>
#define MAX 99
typedef struct node {
    int vertex;
    struct node* next;
} *GNODE;

GNODE graph[MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

void BFS(int v) {
    GNODE temp;
    visited[v] = 1;
    enqueue(v);
    while (!isEmpty()) {
        v = dequeue();
        printf("\n%d", v);
        for (temp = graph[v]; temp != NULL; temp = temp->next) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                enqueue(temp->vertex);
            }
        }
    }
}
void main() {
	int n, E, s, d, i, j, v;
	GNODE p, q;
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
		if(graph[s]==NULL) {
			graph[s]=q;
		} else {
            p=graph[s];
			while(p->next!=NULL)
				p=p->next;
			p->next=q;
		}
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
	printf("Enter Start Vertex for BFS: ");
	scanf("%d", &v);
	printf("BFS of graph: ");
	BFS(v);
	printf("\n");
}