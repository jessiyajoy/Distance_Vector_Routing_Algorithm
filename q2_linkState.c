// Dijkstra's Algorithm in C

#include <stdio.h>
#include <limits.h>

#define INFINITY 99999


void Dijkstra(int n, int Graph[n][n], int source, int predecessor[], int distance[])
{
    int weight[n][n];
    int visited[n];

    // count : # vertices remaining to be considered
    int count, min_distance, nextnode, i, j;

    // Creating weight matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (Graph[i][j] == 0)
                weight[i][j] = INFINITY;
            else
                weight[i][j] = Graph[i][j];

    for (i = 0; i < n; i++)
    {
        distance[i] = weight[source][i];
        predecessor[i] = source;
        visited[i] = 0;
    }

    distance[source] = 0;
    predecessor[source] = -1;
    visited[source] = 1;

    count = 1;

    while (count < n - 1)
    {
        min_distance = INFINITY;

        for (i = 0; i < n; i++)
            if (distance[i] < min_distance && !visited[i])
            {
                min_distance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        for (i = 0; i < n; i++)
            if (!visited[i])
                if (min_distance + weight[nextnode][i] < distance[i])
                {
                    distance[i] = min_distance + weight[nextnode][i];
                    predecessor[i] = nextnode;
                }

        count++;
    }

}

void printMatrix(int source, int n, int predecessor[], int distance[]) {

    printf("\nnode %d\n", source);

    printf("   distance vector = [ ");
    for (int i = 0; i < n; i++) {
        if(distance[i] >= 0)
            printf("%d ", distance[i]);
        else
            printf("INF ");
    }

    printf(" ]\n");

    printf("   predecessor vector = [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", predecessor[i]);
    }

    printf(" ]\n");

    return;

}

int main()
{

    int n, m;

    scanf("%d %d", &n, &m);

    int Graph[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Graph[i][j] = 0;
    

    int u, v, w;

    for(int i = 0; i < m; i++) {

        scanf("%d %d %d", &u, &v, &w);

        Graph[u][v] = w;
        Graph[v][u] = w;

    }

    int predecessor[n], distance[n];

    printf("Link State Algorithm using Dijkstra’s executed\n");

    for (int i = 0; i < n; i++)
    {
        Dijkstra(n, Graph, i, predecessor, distance);

        printMatrix(i, n, predecessor, distance);
    }

    return 0;
}