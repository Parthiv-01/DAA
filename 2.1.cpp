#include <iostream>
#include <climits>

using namespace std;

#define V 100

int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V], int vertices)
{
    cout << "\nEdge \tWeight\n";
    int cost = 0;
    for (int i = 1; i < vertices; i++)
    {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
        cost += graph[i][parent[i]];
    }
    cout << "minimum cost : " << cost << endl;
}

void primMST(int graph[V][V], int vertices)
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = true;

        for (int v = 0; v < vertices; v++)

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, vertices);
}

int main()
{
    int vertices, edge;
    cout << "\nEnter the number of vertices: ";
    cin >> vertices;

    int graph[V][V];
    cout << "\nEnter total no. of edges:";
    cin >> edge;
    for (int i = 0; i < edge; i++)
    {
        int s, d, w;
        cout << "\nEnter nodes to connect :";
        cin >> s >> d;
        cout << "\nEnter weight :";
        cin >> w;
        graph[s][d] = w;
        graph[d][s] = w;
    }
    primMST(graph, vertices);

    return 0;
}
