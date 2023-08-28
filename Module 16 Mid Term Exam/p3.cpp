#include<bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
const int N=1e3+5;
bool vis[N][N];
char g[N][N];
vector<pi> direc={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool isValid(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m && g[i][j]=='.')
    return true;
    else return false;
}
int bfs(int si, int sj)
{
    queue<pi>q;
    q.push({si,sj});
    vis[si][sj]=true;
    int cmp=1;
    while(!q.empty())
    {
        pi parent=q.front();
        q.pop();
        int pI=parent.first;
        int pJ=parent.second;
        for(int i=0; i<4; i++)
        {
            pi p=direc[i];
            int cI=pI+p.first;
            int cJ=pJ+p.second;
            if(isValid(cI,cJ)  &&  !vis[cI][cJ])
            {
                q.push({cI,cJ});
                vis[cI][cJ]=true;
                cmp++;
            }
        }
    }
    return cmp;

}
int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m;j++)
        {
            cin>>g[i][j];
        }
    }
    int minimum_area=INT_MAX;
    bool found_cmp=false;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!vis[i][j] && g[i][j]=='.')
            {
                int cmp=bfs(i,j);
                found_cmp=true;
                minimum_area=min(minimum_area, cmp);
            }
        }
    }
    if(found_cmp)
    {
        cout<<minimum_area<<endl;
    }
    else
    {
        cout<< -1 <<endl;
    }
    return 0;
}