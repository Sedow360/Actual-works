#include<stdio.h>
#include<limits.h>

int V;

void print(int dist[])
{
    printf("The list of shortest distances:\nVertex \t->\tShortest distance from source\n");
    for (int i=0; i<V; i++)
    {
        printf("%d \t->\t %d\n", i, dist[i]);
    }
}

int bf(int graph[V][V], int src)
{
    int dist[V];

    for (int i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int c=0; c<V-1; c++)
    {
        for (int u=0; u<V; u++)
        {
            for (int v=0; v<V; v++)
            {
                if (dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int u=0; u<V; u++)
    {
        for (int v=0; v<V; v++)
        {
            if (dist[u] + graph[u][v] < dist[v])
            {
                printf("Negative edge cycle!\nFound from %d to %d\nOld: %d, New: %d\n", u, v, dist[v], dist[u]+graph[u][v]);
                return -1;
            }
        }
    }

    print(dist);
    return 0;
}

int main()
{
    printf("No. of cities: ");
    scanf("%d", &V);
    int graph[V][V];

    printf("Enter the edges:\n");
    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int src; printf("Start from: ");
    scanf("%d", &src);

    bf(graph, src);

    return 0;
}