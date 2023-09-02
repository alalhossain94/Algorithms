#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+5;
int main()
{
    int N, E;
    cin>>N>>E;
    long long int dis[N+1][N+1];
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            dis[i][j]=LONG_MAX;
            if(i==j) dis[i][j]=0;
        }
    }
    while(E--)
    {
        long long int A,B,W;
        cin>>A>>B>>W;
        if(dis[A][B] > W)
        {
            dis[A][B] = W;
        }
        
    }
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(dis[i][k] !=LONG_MAX && dis[k][j] !=LONG_MAX )
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
        if(dis[X][Y]==LONG_MAX)
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