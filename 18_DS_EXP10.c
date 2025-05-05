/*Write a C program to construct a Minimum Cost Spanning Tree (MST) using Prim's Algorithm, printing the selected edges and the total minimum cost.
Note: The main function is already provided; complete the prims() function to implement Prim's Algorithm.*/

#include<stdio.h>
#include<conio.h>
int cost[100][100];
int n, e;
int i, j, s, d, w;

void prims() {
	int selected[100] = {0};
	int no_of_edges = 0;
	int x = 0, y = 0;
	int min, total_cost = 0;

	selected[1] = 1; 

	while (no_of_edges < n - 1) {
		min = 1000000; 
		for (i = 1; i <= n; i++) {
			if (selected[i]) {
				for (j = 1; j <= n; j++) {
					if (!selected[j] && cost[i][j] != 0 && cost[i][j] < min) {
						min = cost[i][j];
						x = i;
						y = j;
                    }
				}
			}
		}

		if (min != 1000000) {
			printf("Edge cost from %d to %d : %d\n", x, y, cost[x][y]);
			total_cost += cost[x][y];
			selected[y] = 1;
			no_of_edges++;
		}
	}

	printf("Minimum cost of spanning tree = %d\n", total_cost);
}
void main() {
	printf("Enter the number of vertices : ");
	scanf("%d", &n);
	printf("Enter the number of edges : ");
	scanf("%d", &e);
	for(i=1; i<=e; i++) {
        printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s <= 0 || d <= 0 || s > n || d > n || w < 0 ) {
			printf("Invalid data.Try again.\n");
			i--;
			continue;
		}
		cost[s][d] = w;
		cost[d][s] = w;
	}
	for(i=1; i <= n; i++) {
	    for(j=1; j<=n; j++) {
			if(cost[i][j] == 0)
			    cost[i][j] = 999;
	    }
	}
    printf("The edges of Minimum Cost Spanning Tree are : \n");
	prims();
}