#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
    void DFS(int startVertex);
    void print(int V);
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::print(int V)
{
    for (int d = 0; d < V; d++)
    {
        cout << "\n Vertex " << d << " : " << d;
        for (auto x : adjLists[d])
        {
            cout << " --> " << x;
        }
        printf("\n");
    }
}

void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << currVertex << " ";
        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }
    }
}

void Graph::DFS(int startVertex)
{
    visited[startVertex] = true;
    list<int> adjList = adjLists[startVertex];
    cout << startVertex << " ";

    list<int>::iterator i;
    for (i = adjList.begin(); i != adjList.end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i);
        }
    }
}

int main()
{
    int V, choice;
    cout << "\n Enter no. of vertices : ";
    cin >> V;
    Graph g(V);
    do
    {
        int choice;
        cout << "\n---------\t"
             << "\t---------\t"
             << "\t---------\t"
             << "\t---------\t"
             << "\t---------\n";
        cout << "\n 0 ==> print graph ; 1 ==> add edge ; 2 ==> BFS ; 3 ==> DFS ; -1 ==> EXIT\n";
        cout << "\nEnter choice : ";
        cin >> choice;

        if (choice == 0)
        {
            g.print(V);
        }
        if (choice == 1)
        {
            int s, d;
            cout << "Enter source & destiation : ";
            cin >> s >> d;
            g.addEdge(s, d);
        }
        if (choice == 2)
        {
            int sv;
            cout << "Enter starting vertex : ";
            cin >> sv;
            g.BFS(sv);
        }
        if (choice == 3)
        {
            int sv;
            cout << "Enter starting vertex : ";
            cin >> sv;
            g.DFS(sv);
        }
    } while (choice != -1);
    return 0;
}