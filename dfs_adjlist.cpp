
#include <iostream>
#include <list>
using namespace std;

const int MAX_VERTICES = 100;

list<int> adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];

void addEdge(int u, int v, int n)
{
    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        cout << "Invalid edge!\n";
        return;
    }

    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void dfs(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : adjList[vertex])
    {
        if (visited[neighbor] == false)
        {
            dfs(neighbor);
        }
    }
}

int main()
{
    int n, edges, u, v, startVertex;

    cout << "Enter number of vertices (1-100): ";
    if (!(cin >> n) || n <= 0 || n > MAX_VERTICES)
    {
        cout << "Invalid number of vertices!\n";
        return 0;
    }

    cout << "Enter number of edges: ";
    if (!(cin >> edges) || edges < 0 ||
        edges > n * (n - 1) / 2)
    {
        cout << "Invalid number of edges!\n";
        return 0;
    }

    cout << "Enter edges (u v), vertices numbered 0 to "
         << n - 1 << ":\n";

    for (int i = 0; i < edges; i++)
    {
        if (!(cin >> u >> v))
        {
            cout << "Invalid input!\n";
            return 0;
        }

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            cout << "Invalid edge!\n";
            return 0;
        }

        addEdge(u, v, n);
    }

    cout << "Enter starting vertex: ";
    if (!(cin >> startVertex) ||
        startVertex < 0 || startVertex >= n)
    {
        cout << "Invalid starting vertex!\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "DFS Traversal: ";
    dfs(startVertex);
    cout << endl;

    return 0;
}
