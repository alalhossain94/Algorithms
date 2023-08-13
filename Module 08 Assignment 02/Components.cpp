#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int> adj[N];
bool visited[N];

void dfs(int u, int &c_sz)
{
    visited[u]=true;
    c_sz++;
    for(int v:adj[u])
    {
        if(visited[v]== true) continue;
        dfs(v,c_sz);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
         int A, B;
         cin>>A>>B;
         adj[A].push_back(B);
         adj[B].push_back(A);
    }
    vector<int>c_sizes;
    for(int i=0; i<N; i++)
    {
        if(visited[i]==true) continue;
        {
            int c_sz=0;
            dfs(i, c_sz);
            if(c_sz > 1)
            {
                c_sizes.push_back(c_sz);
            }
        }
    }
    sort(c_sizes.begin(), c_sizes.end());
    for(int number_of_nodes: c_sizes)
    {
        cout<< number_of_nodes<<" ";
    }
    return 0;
}