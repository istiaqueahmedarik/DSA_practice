#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];
int c = 0;
void dfs(int node, int parent)
{
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i, node);
        }
        else if (visited[i] && i != parent)
            c++;
    }
}
int main()
{
    int edges;
    cin >> edges;
    set<int> nodes;
    while (edges--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        nodes.insert(u);
        nodes.insert(v);
    }
    dfs(0, -1);
    cout << c / 2 << endl;
}