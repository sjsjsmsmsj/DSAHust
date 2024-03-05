#include <iostream>
#include <vector>
using namespace std;
/*
Input
9 10
1 2
1 3
1 5
2 4
3 6
3 7
3 9
5 8
6 7
8 9
9 3
*/

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    memset(visited, false, sizeof(visited));
}

void dFS(int u) {
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dFS(v);
        }
    } 
}

int main() {
    input();
    cout << endl;
    dFS(1);
    return 0;
}