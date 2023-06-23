#include <bits/stdc++.h>
#define int long long
#define float double
#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

using namespace std;
unordered_map<string, string> country;
unordered_map<string, string> capital;
unordered_map<string, vector<string>> adj;
unordered_map<string, bool> Done, visited, present;
unordered_map<string, int> levels;
unordered_map<string, string> parent;
void bfs(string s)
{
    queue<string> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        string u = q.front();
        q.pop();
        for (auto i : adj[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
                parent[i] = u;
                levels[i] = levels[u] + 1;
            }
        }
    }
}
void printPath(string x, string m)
{

    if (x == capital[country[x]])
    {
        cout << x << "--> ";
        return;
    }
    printPath(parent[x], m);
    if (x == m)
        cout << x << endl;
    else
        cout << x << "--> ";
}
int32_t main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        cin >> a >> b >> c;
        if (a[0] >= 'A' && a[0] <= 'Z')
            capital[c] = a;
        else if (b[0] >= 'A' && b[0] <= 'Z')
            capital[c] = b;
        present[a] = present[b] = present[c] = true;
        country[a] = country[b] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string x;
        cin >> x;
        if (!Done[capital[country[x]]])
            bfs(capital[country[x]]);
        if (present[x])
        {
            cout << country[x] << endl;
            cout << capital[country[x]] << endl;
            printPath(x, x);
            cout << levels[x] * 100 << " km" << endl;
            cout << endl
                 << endl;
        }
        else
            cout << "City not found" << endl;
        cout << endl
             << endl;
    }
    return 0;
}