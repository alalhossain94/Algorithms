#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int level[MAXN];
bool visited[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    int L;
    cin >> L;

    // Initialize visited array with false
    // memset(visited, false, sizeof(visited));

    // Start BFS from level 0
    bfs(0);

    vector<int> pizzaShops;

    // Find pizza shops at level L
    for (int i = 0; i < N; i++) {
        if (level[i] == L) {
            pizzaShops.push_back(i);
        }
    }

    if (pizzaShops.empty()) {
        cout << -1 << endl;
    } else {
        for (int shop : pizzaShops) {
            cout << shop << " ";
        }
        cout << endl;
    }

    return 0;
}
