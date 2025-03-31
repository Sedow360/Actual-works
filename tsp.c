#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100

void greedy_tsp(int graph[MAX][MAX], int n, int start, int tour[])
{
    int visited[MAX];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;  // Initialize all cities as unvisited
    }

    visited[start] = 1;
    int tot_dist = 0;
    int curr = tour[0] = start;
    int tour_len = 1;

    for (int i=0; i<n-1; i++)
    {
        int next = -1;
        int dist = INT_MAX;

        for (int j = 0; j<n; j++)
        {
            if (graph[curr][j]>0 && !visited[j] && graph[curr][j] < dist)
            {
                next = j;
                dist = graph[curr][j];
            }
        }
        printf("%d -> %d\n", curr, next);

        if (next ==-1)
        {
            printf("No path to an unvisited city exists from city %d.\n", curr);
            break;
        }
        tour[tour_len++] = next;
        visited[next] = 1;
        curr = next;
        printf("Iteration: %d: %d(prev) + %d(edge)\n", i+1, tot_dist, dist);
        tot_dist += dist;
    }

    if (graph[curr][start] > 0)
    {
        tot_dist += graph[curr][start];
        tour[tour_len] = start;
        printf("Returning to start: %d -> %d (distance: %d)\n", curr, start, graph[curr][start]);
    }
    else
    {
        printf("No direct path from city %d to starting city %d.\n", curr, start);
    }

    printf("Total distance traveled: %d\n", tot_dist);
    printf("Route followed: ");
    for (int i=0; i<=n; i++)
    {
        printf("%d ", tour[i]);
    }
}

int main()
{
    int n; printf("No. of cities: ");
    scanf("%d", &n);
    int graph[MAX][MAX];
    int tour[MAX];

    printf("Enter the edges:\n");
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    int start; printf("Start from: ");
    scanf("%d", &start);

    greedy_tsp(graph, n, start, tour);

    return 0;
}