#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=105;
int dis[N][N];
vector<pi> direc={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,-2},{2,-1},{1,2},{2,1}};
bool isValid(int i, int j, int n, int m)
{
    if(i>=0 && i<n && j>=0 && j<m)
    return true;
    else return false;  
}
int bfs(int ki, int kj, int qi, int qj, int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dis[i][j]=-1;
        }
    }
    queue<pi>q;
    q.push({ki,kj});
    dis[ki][kj]=0;
    while(!q.empty())
    {
        pi parent=q.front();
        q.pop();
        int pI=parent.first;
        int pJ=parent.second;
        if(pI==qi && pJ==qj)
        {
            return dis[pI][pJ];
        }
        for(pi move: direc)
        {
            int cI=pI+move.first;
            int cJ=pJ+move.second;
            if(isValid(cI,cJ,n,m) && dis[cI][cJ]==-1)
            {
                dis[cI][cJ]=dis[pI][pJ]+1;
                q.push({cI,cJ});
            }
        }
    }
    return -1;
}
int main()
{   
    int T;
    cin>>T;
    while(T--)
    {
        int n, m, ki, kj, qi, qj;
        cin>>n>>m>>ki>>kj>>qi>>qj;
        int result=bfs(ki,kj,qi,qj,n,m);
        cout<<result<<endl;
    }

    return 0;
}