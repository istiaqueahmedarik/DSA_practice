#include <bits/stdc++.h>
using namespace std;
vector<int> adj[1000];
bool visited[1000];
int c = 0;
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
            else
                c++;
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
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i])
            bfs(i);
    }
    cout << c / 2 << endl;
}