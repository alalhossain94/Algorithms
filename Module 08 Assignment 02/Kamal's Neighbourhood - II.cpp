#include<bits/stdc++.h>
using namespace std;
const int N=21;
vector<int>adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
    {   
        if(visited[v]==true) continue;
        dfs(v);
    }
}
int main()
{   
    int N,E;
    cin>>N>>E;
    for(int i=0; i<E; i++)
    {
        int A,B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    int k;
    cin>>k;
    dfs(k);
    int numbers_of_houses_that_kamal_can_go=0;
    for(int i=0; i<N; i++)
    {
        if(visited[i]==true)
        {
            numbers_of_houses_that_kamal_can_go++;
        }
    }
    cout<<numbers_of_houses_that_kamal_can_go-1<<endl;
    return 0;
}