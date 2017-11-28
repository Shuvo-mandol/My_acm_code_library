#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];
int visited[100];
int level[100];
int parent[100];

int bfs(int src, int des)              // Functions for finding shortest distance between nodes
{
    if(src == des)
        return 0;

    queue<int> Q;
    Q.push(src);
    visited[src] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(! visited[v])
            {
                Q.push(v);
                visited[v] = 1;
                level[v] = level[u] + 1;
                parent[v] = u;
                if(v == des)
                    return level[v];
            }
        }
        Q.pop();
    }

    return -1;
}

void findPath(int src, int des)       // Functions for finding path between nodes
{
    if(src == des)
    {
        cout<< src;
        return;
    }
    else
    {
        findPath(src, parent[des]);
        cout<<" --> "<<des;
    }
}

int main()
{
    int n;
    cin >> n;                        // Total edges
    for(int i=0; i<n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int src, des;
    cout<<"Enter the source node : ";
    cin >> src;
    cout<<"Enter the destination node : ";
    cin >> des;
    int res;
    res = bfs(src, des);
    if(res >= 0)
    {
        cout<<"\nShortest path is : "<< res;
        cout<<"\nPath is : ";
        findPath(src, des);
        cout<<"\n";
    }
    else
        cout<<"\nNot found\n";
    return 0;
}
