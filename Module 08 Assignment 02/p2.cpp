#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start]=true;
    level[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (visited[v]==true) continue; 
            {
                level[v] = level[u] + 1;
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

int main() 
{
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

    // Initialize level array with -1
    // for (int i = 0; i < N; i++) {
    //     level[i] = false;
    // }

    // Start BFS from level 0
    bfs(0);

    vector<int> pizzaShops;

    // Find pizza shops at level L
    for (int i = 0; i < N; i++) {
        if (level[i] == L) {
            pizzaShops.push_back(i);
        }
    }

    // if (pizzaShops.empty()) {
    //     cout << -1 << endl;
    // } else {
    //     for (int shop : pizzaShops) {
    //         cout << pizzaShops << " ";
    //     }
    //     cout << endl;
    // }
    // bool found = false;

    // Output pizza shops at level L
    // for (int i = 0; i < N; i++) {
    //     if (level[i] == L) {
    //         cout << i << " ";
    //         found = true;
    //     }
    // }

    // if (!found) {
    //     cout << -1;
    // }
    // cout << endl;


    

    return 0;
}

