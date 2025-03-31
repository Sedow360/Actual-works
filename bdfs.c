#include<stdio.h>
#include<stdlib.h>

struct graphMatrix
{
    int numVertices;
    int** gm;
};

struct graphMatrix* create(int vertices)
{
    struct graphMatrix* graph = (struct graphMatrix*)malloc(sizeof(struct graphMatrix));
    graph->numVertices = vertices;
    graph->gm = (int**)malloc(vertices*sizeof(int*));

    for (int i = 0; i<vertices; i++)
    {
        graph->gm[i] = (int*)malloc(vertices*sizeof(int));
        for (int j =0; j<vertices; j++)
        {
            graph->gm[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(struct graphMatrix* graph, int src, int des)
{
    if (src >= 0 && src <graph->numVertices && des >= 0 && des < graph->numVertices)
    {graph->gm[src][des] = graph->gm[des][src] = 1;}
}

void printG(struct graphMatrix* graph)
{
    for(int i = 0; i<graph->numVertices; i++)
    {
        for (int j=0; j<graph->numVertices; j++)
        {
            printf("%d", graph->gm[i][j]);
        }
        printf("\n");
    }
}

int check(int* a, int n, int l)
{
    for (int i = 0; i<l; i++)
    {
        if (a[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

void bfs(struct graphMatrix* graph, int start)
{
    int* visited = (int*)malloc(graph->numVertices*sizeof(int));
    for (int i = 0; i<graph->numVertices; i++)
    {
        visited[i] = 0;
    }
    int* queue = (int*)malloc(graph->numVertices*sizeof(int));

    int front=0, rear=0;

    queue[rear++] = start;

    while(front<rear)
    {
        int temp = queue[front++];
        visited[temp] = 1;
        printf("Visited %d\n", temp);

        for (int j = 0; j<graph->numVertices; j++)
        {
            if (graph->gm[temp][j] == 1 && visited[j] == 0 && check(queue, j, graph->numVertices) == 0)
            {
                queue[rear++] = j;
            }
        }
    }

    free(visited);
    free(queue);
}


void dfs(struct graphMatrix* graph, int start)
{
    int* visited = (int*)malloc(graph->numVertices*sizeof(int));
    for (int i = 0; i<graph->numVertices; i++)
    {
        visited[i] = 0;
    }
    int* stack = (int*)malloc(graph->numVertices*sizeof(int));

    int rear = 0;

    stack[rear++] = start;

    while (rear > 0) 
    {
        int temp = stack[--rear]; // Pop the top vertex from the stack

        if (visited[temp] == 0) 
        { // Check if it has been visited
            visited[temp] = 1; // Mark as visited
            printf("Visited %d\n", temp); // Print the visited vertex

            // Push all unvisited adjacent vertices onto the stack
            for (int j = 0; j < graph->numVertices; j++) 
            {
                if (graph->gm[temp][j] == 1 && visited[j] == 0) 
                {
                    stack[rear++] = j; // Push the unvisited vertex onto the stack
                }
            }
        }
    }

    free(visited);
    free(stack);
}

void freeGraph(struct graphMatrix* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->gm[i]);
    }
    free(graph->gm);
    free(graph);
}

int main() {
    int vertices, choice, src, dest, startVertex;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    struct graphMatrix* graphMatrix = create(vertices);

    while (1) {
        printf("\nGraph Operations:\n");
        printf("1. Add Edge\n");
        printf("2. Print Graph (Adjacency Matrix)\n");
        printf("3. BFS\n");
        printf("4. DFS\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                addEdge(graphMatrix, src, dest);
                break;
            case 2:
                printf("Graph (Adjacency Matrix):\n");
                printG(graphMatrix);
                break;
            case 3:
                printf("Enter the start vertex for BFS: ");
                scanf("%d", &startVertex);
                bfs(graphMatrix, startVertex);
                break;
            case 4:
                printf("Enter the start vertex for DFS: ");
                scanf("%d", &startVertex);
                dfs(graphMatrix, startVertex);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    freeGraph(graphMatrix);
    return 0;
}