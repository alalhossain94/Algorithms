#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;

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
        }
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
        adj[B].push_back(A);
    }
    int L;
    cin>>L;

    bfs(0);

    vector<int>v;
    for(int i=0; i<N; i++)
    {
        if(level[i]==L)
        {
            v.push_back(i); 
        }
    }
    if(v.empty())
    {
        cout<< -1 <<endl;
    }
    else
    {
        for(int pizzaShops:v)
        {
            cout<< pizzaShops << " ";
        }
    }
    cout << endl;
    return 0;
}

