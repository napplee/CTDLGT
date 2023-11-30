#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class DirectedGraph {
public:
    DirectedGraph(int vertices) : V(vertices) {
        adj.resize(V);
        inDegree.resize(V, 0);
        outDegree.resize(V, 0);
        visited.resize(V, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        outDegree[u]++;
        inDegree[v]++;
    }

    bool hasUniqueTopologicalOrder() {
        if (hasHamiltonianCycle()) {
            cout << "Do thi co chu trinh Hamilton, khong co thu tu to po duy nhat.\n";
            return false;
        }

        int startVertex = 0;

        vector<int> path;
        if (findHamiltonianPath(startVertex, path)) {
            cout << "Do thi co thu tu to po duy nhat.\n";
            return true;
        } else {
            cout << "Do thi khong co thu tu to po duy nhat.\n";
            return false;
        }
    }

private:
    int V;
    vector<vector<int>> adj;
    vector<int> inDegree;
    vector<int> outDegree;
    vector<bool> visited;

    bool hasHamiltonianCycle() {
        for (int i = 0; i < V; ++i) {
            if (outDegree[i] != inDegree[i]) {
                return true;
            }
        }
        return false;
    }

    bool isSafe(int v, int pos, const vector<int>& path) {
        if (!visited[v] && outDegree[path[pos - 1]] > 0) {
            return true;
        }
        return false;
    }

    bool findHamiltonianPath(int v, vector<int>& path) {
        if (path.size() == V) {
            if (outDegree[path.back()] > 0) {
                return true;
            }
            return false;
        }

        for (int i : adj[v]) {
            if (isSafe(i, path.size(), path)) {
                path.push_back(i);
                visited[i] = true;

                if (findHamiltonianPath(i, path)) {
                    return true;
                }

                path.pop_back();
                visited[i] = false;
            }
        }

        return false;
    }
};

int main() {
    DirectedGraph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.hasUniqueTopologicalOrder();

    return 0;
}
