#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int weight;
};

bool cmp(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskal(Edge *input, int n, int E)
{
    sort(input, input + E, cmp);

    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i];
        int srcParent = findParent(currentEdge.src, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (srcParent != destParent)
        {
            output[count] = currentEdge;
            count++;
            parent[srcParent] = destParent;
        }
        i++;
    }

    int cost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << output[i].src << " ---> " << output[i].dest << " weight: " << output[i].weight << endl;
        cost += output[i].weight;
    }
    cout << "Total Cost = " << cost;
}

int main()
{
    int n, E;
    cout << "Enter total no. of verteces & edges :";
    cin >> n >> E;
    Edge *input = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cout << "Enter source, destination & weight :";
        cin >> s >> d >> w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskal(input, n, E);
}