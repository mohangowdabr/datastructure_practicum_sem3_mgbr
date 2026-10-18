
#include <iostream>
#include <list>
using namespace std;

const int MAX_VERTICES = 100;

list<int> adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];
int queueArr[MAX_VERTICES];
int front = -1, rear = -1;

bool isQueueEmpty()
{
    return front == -1 || front > rear;
}

void enqueue(int value)
{
    if (rear == MAX_VERTICES - 1)
    {
        cout << "Queue overflow!\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queueArr[rear] = value;
}

int dequeue()
{
    if (isQueueEmpty())
    {
        cout << "Queue underflow!\n";
        return -1;
    }

    int value = queueArr[front];
    front++;

    return value;
}

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

void bfs(int startVertex, int n)
{
    if (startVertex < 0 || startVertex >= n)
    {
        cout << "Invalid starting vertex!\n";
        return;
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    front = -1;
    rear = -1;

    visited[startVertex] = true;
    enqueue(startVertex);

    cout << "BFS Traversal: ";

    while (!isQueueEmpty())
    {
        int currentVertex = dequeue();
        cout << currentVertex << " ";

        for (int neighbor : adjList[currentVertex])
        {
            if (visited[neighbor] == false)
            {
                visited[neighbor] = true;
                enqueue(neighbor);
            }
        }
    }

    cout << endl;
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
        cin >> u >> v;

        if (!cin)
        {
            cout << "Invalid input!\n";
            return 0;
        }

        addEdge(u, v, n);
    }

    cout << "Enter starting vertex: ";
    if (!(cin >> startVertex))
    {
        cout << "Invalid input!\n";
        return 0;
    }

    bfs(startVertex, n);

    return 0;
}
