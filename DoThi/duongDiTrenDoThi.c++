#include <iostream>
#include <vector>
#include <cstring> // Include <cstring> for memset
#include <algorithm> // Include <algorithm> for reverse

using namespace std;
/*
10 8
1 2 
2 3
2 4
3 6
3 7
6 7
5 8
8 9
*/

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u) {
    visited[u] = true;
    for (int x : adj[u]) {
        if (!visited[x]) {
            parent[x] = u;
            dfs(x);
        }
    }
}

void path(int s, int t) {
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if (!visited[t]) {
        cout << "Khong co duong di" << endl;
    } else {
        vector<int> pathTwo;
        while (t != s) {
            pathTwo.push_back(t);
            t = parent[t];
        }
        pathTwo.push_back(s);
        reverse(pathTwo.begin(), pathTwo.end());
        for (int x : pathTwo) {
            cout << x << " ";
        }
    }
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(! q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : adj[x]) {
            q.push(x);
            visited[x] = true;
            parent[x] = v;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s >> t;
    path(s, t);
    return 0;
}
