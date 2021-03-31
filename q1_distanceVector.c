// Bellman Ford Algorithm in C

#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

//struct for the edges of the graph
struct Edge
{
    int u; //vertex 1
    int v; //vertex 2
    int w; //weight of edge
};

//Graph - it consists of edges
struct Graph
{
    int n;             // #vertices
    int m;             // #edges
    struct Edge * edges; // edges array
};


void printVector(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" ]\n");
}

void bellmanford(struct Graph *g, int source)
{
    //variables
    int i, j, u, v, w;

    int n = g->n;
    int m = g->m;

    //distance array
    int distance[n];

    //predecessor array
    int predecessor[n];

    for (i = 0; i < n; i++)
    {
        distance[i] = INFINITY;
        predecessor[i] = source;
    }

    distance[source] = 0;
    predecessor[source] = -1;

    //relax edges |V| - 1 times
    for (i = 1; i <= n - 1; i++)
    {
        for (j = 0; j < m; j++)
        {
            //get the edge data
            u = g->edges[j].u;
            v = g->edges[j].v;
            w = g->edges[j].w;

            if (distance[u] != INFINITY && distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                predecessor[v] = u;
            }

            if (distance[v] != INFINITY && distance[u] > distance[v] + w)
            {
                distance[u] = distance[v] + w;
                predecessor[u] = v;
            }
        }
    }

    //prints distance and predecessor vectors for each node

    printf("\nnode %d\n", source);
    printf("   distance vector = [ ");
    printVector(distance, n);

    printf("   predecessor vector = [ ");
    printVector(predecessor, n);
}


int main()
{
    //create graph
    struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));

    scanf("%d %d", &(G->n), &(G->m));

    //array of edges for graph
    G->edges = (struct Edge *)malloc(G->m * sizeof(struct Edge));

    for(int i = 0; i < G->m; i++) {
        scanf("%d", &(G->edges[i].u));
        scanf("%d",&(G->edges[i].v));
        scanf("%d", &(G->edges[i].w));
    }

    printf("Distance Vector Routing algorithm using Bellman-Ford executed\n");

    for (int i = 0; i < G->n; i++)
        bellmanford(G, i);

    return 0;
}

