#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
    parent[s]=-1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;  
            parent[v]=u;
        }
    }
}
int main()
{   
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int A,B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    bfs(1);
    
    cout<<level[n]<<endl;
    vector<int> path;
    int current=n;
    while(current != -1)
    {
        path.push_back(current);
        current=parent[current];
    }
    reverse(path.begin(), path.end());
    cout<< "Path : ";
    for(int node:path)
    {
        cout<< node<<" ";
    }

    return 0;
}

