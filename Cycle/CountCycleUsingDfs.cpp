#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];
int c = 0;
void dfs(int node, int parent)
{
    for (auto i : adj[node])
    {
        if (!visited[node])
        {
            visited[node] = true;
            dfs(i, node);
        }
        else if (visited[i] && i != parent)
            c++;
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
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
            dfs(i, 0);
    }
    cout << c / 2 << endl;
}