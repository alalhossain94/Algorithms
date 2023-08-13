#include<bits/stdc++.h>
using namespace std;

const int MAXN = 21;
vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }

    int K;
    cin >> K;

    dfs(K);

    int reachableHouses = 0;
    for (int i = 0; i < N; ++i) {
        if (visited[i]) {
            reachableHouses++;
        }
    }

    cout << reachableHouses - 1 << endl; // Exclude Kamal's house

    return 0;
}
