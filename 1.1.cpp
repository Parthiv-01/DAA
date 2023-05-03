#include <iostream>
#include <queue>
using namespace std;

void dfs(int **edges, int n, int sv, bool *visited)
{
    cout << " " << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            dfs(edges, n, i, visited);
        }
    }
}

void bfs(int **edges, int n, int sv, bool *visited)
{
    int queue[n], rear = -1, front = -1, i, k;
    queue[++rear] = sv;
    ++front;
    visited[sv] = true;
    while (rear >= front)
    {
        sv = queue[front++];
        cout << " " << sv << " ";
        for (i = 0; i < n; i++)
        {
            if (edges[sv][i] && visited[i] == false)
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
}

int main()
{
    cout << "\n\nEnter no. of vertices & edges : ";
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cout << "\nEnter vertices to join (range [0," << n - 1 << "]) : ";
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int choice;
    do
    {
        cout << "\n---------\t"
             << "\t---------\t"
             << "\t---------\t"
             << "\t---------\t"
             << "\t---------\n";
        cout << "\n 0 ==> Adjacency Matrix; 1 ==> DFS ; 2 ==> BFS ; -1 ==> EXIT \n";
        cout << "\n Enter choice :";
        cin >> choice;
        if (choice == 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << " " << edges[i][j];
                }
                cout << "\n";
            }
        }
        if (choice == 1)
        {
            bool *visited = new bool[n];
            for (int i = 0; i < n; i++)
            {
                visited[i] = false;
            }
            int sv;
            cout << "Enter starting vertex : ";
            cin >> sv;
            dfs(edges, n, sv, visited);
        }
        if (choice == 2)
        {
            bool *visited = new bool[n];
            for (int i = 0; i < n; i++)
            {
                visited[i] = false;
            }
            int sv;
            cout << "Enter starting vertex : ";
            cin >> sv;
            bfs(edges, n, sv, visited);
        }
    } while (choice != -1);
    return 0;
}