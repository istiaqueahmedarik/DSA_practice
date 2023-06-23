#include <bits/stdc++.h>
using namespace std;
class Prims
{
    vector<pair<int, int>> adj[1000];
    bool visited[1000] = {false};

public:
    void addEdges(int u, int v, int w)
    {
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int countCycle(int src)
    {
        int c = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        visited[src] = false;
        while (!pq.empty())
        {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if (visited[u])
                continue;
            visited[u] = true;
            c += w;
            for (auto i : adj[u])
            {
                if (!visited[i.second])
                {
                    pq.push(i);
                }
            }
        }
        return c;
    }
};
int main()
{
    Prims k;
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        k.addEdges(u, v, w);
    }
    int c = k.countCycle(1);
    cout << c << endl;
}