#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for (int x : adj[u]) {
        if (! visited[x]) {
            dfs(x);
        }
    }
}

int ConnectedComponent() {
    int count = 0;
    for (int i = 1; i <= n;i ++) {
        if (!visited[i]) {
            count ++;
            dfs(i);
        }
    }
    return count;
}

int main() {
    input();
    printf("count = %d", ConnectedComponent());
    return 0;
}