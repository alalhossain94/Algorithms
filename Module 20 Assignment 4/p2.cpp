#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+5;
int main()
{
    int N, E;
    cin>>N>>E;
    int dis[N+1][N+1];
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            dis[i][j]=INF;
            if(i==j) dis[i][j]=0;
        }
    }
    while(E--)
    {
        int A,B,W;
        cin>>A>>B>>W;
        dis[A][B]=min(dis[A][B],W);
        dis[B][A]=min(dis[B][A],W);
    }
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(dis[i][k] !=INF && dis[k][j] !=INF )
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int X,Y;
        cin>>X>>Y;
        if(dis[X][Y]==INF)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<dis[X][Y]<<endl;
        }

    } 
    return 0;
}