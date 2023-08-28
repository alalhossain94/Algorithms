#include<bits/stdc++.h>
using namespace std;
bool Edges_comparison(pair<int,int>& edge1, pair<int, int>& edge2)
{
    if(edge1.first== edge2.first )
    {
        return edge1.second < edge2.second;
    }
    return edge1.first < edge2.first;
}
int main()
{
    int E;
    cin>>E;
    vector<pair<int,int>> v;
    for(int i=0; i<E; i++)
    {
        int A,B;
        cin>>A>>B;
        v.push_back({A,B});
    }
    sort(v.begin(), v.end(), Edges_comparison);
    for(auto edge:v)
    {
        cout<<edge.first<<" "<<edge.second<<endl;
    }
    return 0;
}

