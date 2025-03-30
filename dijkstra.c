#include<stdio.h>
#include<limits.h>

int V;

int minDex(int dist[], int used[])
{
    int min = __INT_MAX__, mind = -1;

    for (int i=0; i<V; i++)
    {
        if (!used[i] && dist[i]<min)
        {
            mind = i;
            min = dist[i];
        }
    }

    return mind;
}

void print(int dist[])
{
    printf("The list of shortest distances:\nVertex \t->\tShortest distance from source\n");
    for (int i=0; i<V; i++)
    {
        printf("%d \t->\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V], used[V];

    for (int i=0; i<V; i++)
    {
        dist[V] = __INT_MAX__, used[i] = 0;
    }

    dist[src] = 0;

    for (int c=0; c<V-1; c++)
    {
        int u = minDex(dist, used);

        used[u] = 1;

        for (int v=0; v<V; v++)
        {
            if (dist[u] == __INT_MAX__)
            break;

            if (!used[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    print(dist);
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

    dijkstra(graph, src);

    return 0;
}