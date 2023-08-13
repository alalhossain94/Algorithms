#include<bits/stdc++.h>
using namespace std;
const int N=21;
vector<int>adj[N];
bool visited[N];
int main()
{
    int N, E;
    cin>>N>>E;
    for(int i=0; i<E; i++)
    {
        int A, B;
        cin>>A>>B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int K;
    cin>>K;
    visited[K]=true;
    
    return 0;
}