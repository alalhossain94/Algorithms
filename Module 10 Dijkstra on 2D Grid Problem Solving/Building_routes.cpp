#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<bool>visited(N, false);
vector<int>g[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:g[u])
    {
        if(visited[v]==true) continue;
        dfs(v);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int>leaders;
    for(int i=1; i<=n; i++)
    {
        if(visited[i]) continue;
        leaders.push_back(i);
        dfs(i);
    }

    // print leaders
    // for(auto l: leaders)
    // cout<<l<<" ";

    cout<<leaders.size()-1<<endl;
    for(int i=1; i<leaders.size(); i++)
    {
        cout<< leaders[i-1]<< " "<< leaders[i]<<endl;
    }
    return 0;
}