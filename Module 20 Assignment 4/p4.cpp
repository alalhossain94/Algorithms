#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};  
int main()
{
    int n, e;
    cin>>n>>e;
    vector<Edge>v;
    while(e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
    }
    int s; 
    cin>>s;
    int q;
    cin>>q;
    vector<long long int> dis(n+1);
    for(int i=1; i<=n; i++)
    {
        dis[i]=INT_MAX;
    }
    dis[s]=0;
    for(int i=1; i<n-1; i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            Edge ed=v[j];
            int a=ed.u;
            int b=ed.v;
            int w=ed.w;
            if(dis[a] != INT_MAX && dis[a]+w< dis[b])
            {
                dis[b]=dis[a]+ w;
            }
        }
    }
    bool negativeCycle=false;
    for(int j=0; j<v.size(); j++)
    {
        Edge ed=v[j];
        int a=ed.u;
        int b=ed.v;
        int w=ed.w;
        if(dis[a] != INT_MAX && dis[a]+w< dis[b])
        {
            negativeCycle=true;
            break;
        }
    }
    if(negativeCycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        while (q--)
        {
            int d;
            cin >> d;

            if (dis[d] == INT_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}