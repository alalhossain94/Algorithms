#include<bits/stdc++.h>
using namespace std;

const int MAXN = 21;
vector<int> adj[MAXN];

int main() {
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int K;
    cin >> K;

    int connectedHouses = adj[K].size(); // Number of houses directly connected to Kamal's house

    cout << connectedHouses << endl;

    return 0;
}
