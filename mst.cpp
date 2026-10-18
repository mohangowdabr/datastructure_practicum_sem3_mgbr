
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 20;
const int INF = 999999;

struct Edge
{
    int u, v, weight;
};

int parentSet[MAX];

int findParent(int v)
{
    while (parentSet[v] != v)
        v = parentSet[v];

    return v;
}

void prim(int graph[MAX][MAX], int n)
{
    int key[MAX], parent[MAX];
    bool included[MAX];

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        included[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    int total = 0;

    cout << "\nPrim's Algorithm:\n";

    for (int count = 0; count < n; count++)
    {
        int u = -1;
        int minimum = INF;

        for (int i = 0; i < n; i++)
        {
            if (included[i] == false && key[i] < minimum)
            {
                minimum = key[i];
                u = i;
            }
        }

        if (u == -1)
        {
            cout << "Graph is disconnected. MST not possible.\n";
            return;
        }

        included[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] > 0 &&
                included[v] == false &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total weight: " << total << endl;
}

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void kruskal(int graph[MAX][MAX], int n)
{
    Edge edges[MAX * MAX];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] > 0)
            {
                edges[count].u = i;
                edges[count].v = j;
                edges[count].weight = graph[i][j];
                count++;
            }
        }
    }

    sort(edges, edges + count, compareEdges);

    for (int i = 0; i < n; i++)
        parentSet[i] = i;

    int total = 0;
    int selected = 0;

    cout << "\nKruskal's Algorithm:\n";
    cout << "Edges in MST:\n";

    for (int i = 0; i < count && selected < n - 1; i++)
    {
        int u = findParent(edges[i].u);
        int v = findParent(edges[i].v);

        if (u != v)
        {
            cout << edges[i].u << " - " << edges[i].v
                 << " : " << edges[i].weight << endl;

            parentSet[u] = v;
            total += edges[i].weight;
            selected++;
        }
    }

    if (selected != n - 1)
    {
        cout << "Graph is disconnected. MST not possible.\n";
    }
    else
    {
        cout << "Total weight: " << total << endl;
    }
}

int main()
{
    int graph[MAX][MAX];
    int n;

    cout << "Enter number of vertices (1-20): ";

    if (!(cin >> n) || n <= 0 || n > MAX)
    {
        cout << "Invalid number of vertices!\n";
        return 0;
    }

    cout << "Enter weighted adjacency matrix:\n";
    cout << "Enter 0 if there is no edge.\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(cin >> graph[i][j]) || graph[i][j] < 0)
            {
                cout << "Invalid weight!\n";
                return 0;
            }
        }
    }

    prim(graph, n);
    kruskal(graph, n);

    return 0;
}
