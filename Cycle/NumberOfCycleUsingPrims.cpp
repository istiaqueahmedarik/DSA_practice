#include <bits/stdc++.h>
using namespace std;
class Prims
{
    vector<pair<int, int>> adj[1000];
    bool visited[1000];

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
        visited[src] = true;
        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            for (auto i : adj[u])
            {
                if (!visited[i.second])
                {
                    visited[i.second] = true;
                    pq.push({i.first, i.second});
                }
                else
                    c++;
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
    cout << c / 2 << endl;
}