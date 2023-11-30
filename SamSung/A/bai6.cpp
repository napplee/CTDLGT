#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005; 
vector<int> adj[MAXN]; // Danh sách kề
int low[MAXN], disc[MAXN];
bool visited[MAXN];
int timer;

void dfs(int u, int p = -1) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    for (int v : adj[u]) {
        if (v == p) continue; // Bỏ qua đỉnh cha
        if (visited[v]) {
            low[u] = min(low[u], disc[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                // (u, v) là cầu
                cout << "Bridge found: " << u << " - " << v << endl;
            }
        }
    }
}

bool isEdgeConnected(int n) {
    timer = 0;
    fill_n(visited, n, false);
    fill_n(disc, n, -1);
    fill_n(low, n, -1);
    bool hasBridge = false;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (disc[i] == low[i]) {
            hasBridge = true;
            break;
        }
    }

    return !hasBridge;
}

int main() {
    // Ví dụ về cách thêm cạnh vào đồ thị
    // adj[u].push_back(v);
    // adj[v].push_back(u);

    int n = 4; // Số lượng đỉnh
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2};

    if (isEdgeConnected(n)) {
        cout << "The graph is edge connected." << endl;
    } else {
        cout << "The graph is not edge connected." << endl;
    }

    return 0;
}
