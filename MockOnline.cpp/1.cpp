#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
int vis[1000];
void dfs(int node)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
}
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c = 0;
    for (int i = 0; i < nodes; i++)
    {
        if (!vis[i])
            dfs(i), c++;
    }
    cout << c << endl;
}