#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<pair<int,int>> v[N];
int dis[N];
bool vis[N];
void dijkstra(int S) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, S});
    while (!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;
        if (parentCost > dis[parentNode]) 
        {
            continue;
        }
        vis[parentNode]=true;   
        for (auto edge : v[parentNode]) 
        {
            int childNode = edge.first;
            int childCost = edge.second;
            if (parentCost + childCost < dis[childNode]) 
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main() 
{
    int n, e;
    cin >> n >> e;
    while (e--) 
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
    }
    int S;
    cin >> S;
    for (long long int i = 1; i <= n; i++) 
    {
        dis[i] = 1e9 + 1;
        vis[i]=false;
    }
    dis[S] = 0;
    dijkstra(S);
    int T;
    cin >> T;
    while (T--) {
        long long int D, DW;
        cin >> D >> DW;
        if (dis[D] <= DW) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

