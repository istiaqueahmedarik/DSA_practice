#include <bits/stdc++.h>
using namespace std;
class Kruscal
{
    vector<pair<int, pair<int, int>>> adjList;
    int Rep[1000];

public:
    void addEdges(int u, int v, int w)
    {
        adjList.push_back({w, {u, v}});
        adjList.push_back({w, {v, u}});
        Rep[u] = u;
        Rep[v] = v;
    }
    int findRep(int u) { return u == Rep[u] ? u : Rep[u] = findRep(Rep[u]); }
    bool Union(int u, int v)
    {
        int uRep = findRep(u), vRep = findRep(v);
        if (uRep != vRep)
        {
            Rep[uRep] = vRep;
            return true;
        }
        return false;
    }
    int cycles()
    {
        int c = 0;
        sort(adjList.begin(), adjList.end());
        for (auto i : adjList)
        {
            if (!Union(i.second.first, i.second.second))
            {
                c++;
            }
        }
        return c;
    }
};
int main()
{
    Kruscal k;
    int nodes, edges;
    cin >> nodes >> edges;
    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        k.addEdges(u, v, w);
    }
    cout << k.cycles() / 2;
}