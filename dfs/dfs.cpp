#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
int visited[100];

void dfs(int node)                       // Dfs function
{
    visited[node] = 1;
    cout<<node<<" ";
    for(int i=0; i<v[node].size(); i++)
    {
        if(visited[v[node][i]]==0)
            dfs(v[node][i]);
    }
}

int main()
{
    int m, n, x, y;
    cin >> m >> n;
    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);                          // Root node
    return 0;
}
