#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
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
        adj[B].push_back(A);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int S, D;
        cin >> S >> D;

        // Initialize distances for each query
        for (int i = 0; i <N; ++i) {
            dist[i] = -1;
        }

        // Run BFS from the source node
        bfs(S);

        if (dist[D] == -1) {
            cout << "-1" << endl;
        } else {
            cout << dist[D] << endl;
        }
    }

    return 0;
}
