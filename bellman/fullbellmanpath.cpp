// core bellman + printing the shortest path

#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> edges;
const int INF = INT_MAX;
int V, E;
vector<int> dist;
vector<int> parent; // parent vector to store parent

void printpath(int v) // recursively parent print- example- 4-3-2-1
{
    if (v == -1)
        return;
    printpath(parent[v]);
    cout << v << " ";
}

void printshortestdistance(int src)
{
    cout << "Shortest distances from source city " << src << ":\n";
    for (int i = 0; i < V; i++)
    {
        cout << "City " << i << ": ";
        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}
void bellman()
{
    for (int i = 1; i <= V - 1; i++)
    {

        for (auto &[u, v, w] : edges)
        {
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u; // store-- v er parent u
            }
        }
    }
}

void check_negative_cycle()
{
    for (auto &[u, v, w] : edges)
    {
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            cout << "negative loop detected" << endl;
            break;
        }
    }
}

int main()
{

    int src = 0;
    cin >> V >> E;
    dist.assign(V, INF);
    parent.assign(V, -1);
    dist[src] = 0;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    bellman();
    check_negative_cycle();
    printshortestdistance(0);
    printpath(4);

    return 0;
}

// test input-1

// 5 7
// 0 1 -1
// 0 2 4
// 1 2 3
// 1 3 2
// 1 4 2
// 3 2 5
// 4 3 -3

// result-
// Shortest distances from source city 0:
// City 0: 0
// City 1: -1
// City 2: 2
// City 3: -2
// City 4: 1
