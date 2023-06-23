#include <bits/stdc++.h>
using namespace std;
class Kruscal
{
    vector<pair<int, pair<int, int>>> adj;
    int Rep[1000];

public:
    void addEdges(int u, int v, int w)
    {
        adj.push_back({w, {u, v}});
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
    vector<pair<int, pair<int, int>>> KruskalMST()
    {
        vector<pair<int, pair<int, int>>> ans;
        sort(adj.begin(), adj.end());
        for (auto i : adj)
        {
            if (Union(i.second.first, i.second.second))
            {
                ans.push_back(i);
            }
        }
        return ans;
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
    vector<pair<int, pair<int, int>>> ans = k.KruskalMST();
    for (auto i : ans)
    {
        cout << i.first << " " << i.second.first << " " << i.second.second << endl;
    }
}