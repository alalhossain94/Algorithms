                    #include <bits/stdc++.h>
                    #define pi pair<int, int>
                    using namespace std;

                    const int N = 105; // Increased to accommodate constraints
                        mint dist[N][N];

                    vector<pi> moves = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, -2}, {2, -1}, {1, 2}, {2, 1}};

                    bool isValid(int i, int j, int n, int m) {
                        return (i >= 0 && i < n && j >= 0 && j < m);
                    }

                   int bfs(int ki, int kj, int qi, int qj, int n, int m) {
    
     // Initialize distance matrix

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pi> q;
    q.push({ki, kj});
    dist[ki][kj] = 0; // Start position

    while (!q.empty()) {
        pi cell = q.front();
        q.pop();
        int ci = cell.first;
        int cj = cell.second;

        if (ci == qi && cj == qj) // Queen's cell reached
            return dist[ci][cj];

        for (pi move : moves) {
            int ni = ci + move.first;
            int nj = cj + move.second;

            if (isValid(ni, nj, n, m) && dist[ni][nj] == -1) {
                dist[ni][nj] = dist[ci][cj] + 1;
                q.push({ni, nj});
            }
        }
    }

    return -1; // Queen's cell not reachable
}

                    int main() {
                        int t;
                        cin >> t;
                        while (t--) {
                            int n, m, ki, kj, qi, qj;
                            cin >> n >> m >> ki >> kj >> qi >> qj;

                            int result = bfs(ki, kj, qi, qj, n, m);
                            cout << result << endl;
                        }

                        return 0;
                    }
