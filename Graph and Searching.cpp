#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

// DFS - Depth First Search
void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// BFS - Breadth First Search
void BFS(int start)
{
    int queue[MAX];
    int front = 0;
    int rear = 0;

    // Mark starting vertex as visited
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int vertex = queue[front++];
        cout << vertex << " ";

        for (int i = 0; i < n; i++)
        {
            if (graph[vertex][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int edges;
    int u, v;
    int start;

    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter edges (u v):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;   // For undirected graph
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "\nDFS Traversal: ";
    DFS(start);

    // Reset visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // BFS
    cout << "\nBFS Traversal: ";
    BFS(start);

    return 0;
}
