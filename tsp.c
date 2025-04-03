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

/*Test solution:-

No. of cities: 10
Enter the edges:
0 29 82 46 68 52 72 42 51 55
29 0 55 46 42 43 43 23 23 31
82 55 0 68 46 55 23 43 41 29
46 46 68 0 82 15 72 31 62 42
68 42 46 82 0 74 23 52 21 46
52 43 55 15 74 0 61 23 55 31
72 43 23 72 23 61 0 42 23 31
42 23 43 31 52 23 42 0 33 15
51 23 41 62 21 55 23 33 0 29
55 31 29 42 46 31 31 15 29 0
Start from: 0
0 -> 1
Iteration: 1: 0(prev) + 29(edge)
1 -> 7
Iteration: 2: 29(prev) + 23(edge)
7 -> 9
Iteration: 3: 52(prev) + 15(edge)
9 -> 2
Iteration: 4: 67(prev) + 29(edge)
2 -> 6
Iteration: 5: 96(prev) + 23(edge)
6 -> 4
Iteration: 6: 119(prev) + 23(edge)
4 -> 8
Iteration: 7: 142(prev) + 21(edge)
8 -> 5
Iteration: 8: 163(prev) + 55(edge)
5 -> 3
Iteration: 9: 218(prev) + 15(edge)
Returning to start: 3 -> 0 (distance: 46)
Total distance traveled: 279
Route followed: 0 1 7 9 2 6 4 8 5 3 0


*/