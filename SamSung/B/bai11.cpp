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
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        inDegree[v]++;
    }

    bool hasEulerianPath() {
        if (hasCycle()) {
            cout << "Khong ton tai duong di Eulerian trong do thi DAG\n";
            return false;
        }

        int startVertexCount = 0, endVertexCount = 0;
        int startVertex, endVertex;

        for (int i = 0; i < V; ++i) {
            if (inDegree[i] - adj[i].size() == 1) {
                startVertexCount++;
                startVertex = i;
            } else if (adj[i].size() - inDegree[i] == 1) {
                endVertexCount++;
                endVertex = i;
            } else if (inDegree[i] != adj[i].size()) {
                cout << "Khong ton tai duong di Eulerian trong do thi DAG\n";
                return false;
            }
        }

        if (startVertexCount == 1 && endVertexCount == 1) {
            cout << "Duong di Eulerian bat dau tu dinh " << startVertex << "\n";
            return true;
        } else {
            cout << "Khong ton tai duong di Eulerian trong do thi DAG\n";
            return false;
        }
    }

private:
    int V;
    vector<vector<int>> adj;
    vector<int> inDegree;
    vector<bool> visited;

    bool hasCycleUtil(int v, vector<bool>& stack, vector<bool>& visited) {
        if (!visited[v]) {
            visited[v] = true;
            stack[v] = true;

            for (int i : adj[v]) {
                if (!visited[i] && hasCycleUtil(i, stack, visited)) {
                    return true;
                } else if (stack[i]) {
                    return true;
                }
            }
        }

        stack[v] = false;
        return false;
    }

    bool hasCycle() {
        visited.assign(V, false);
        vector<bool> stack(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i] && hasCycleUtil(i, stack, visited)) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    DirectedGraph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 2);

    g.hasEulerianPath();

    return 0;
}
