#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph {
public:
    Graph(int vertices) : V(vertices), indegree(vertices, 0), adj(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        indegree[v]++;
    }

    vector<int> topologicalSort() {
        vector<int> result;
        queue<int> queue;

        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                queue.push(i);
            }
        }

        while (!queue.empty()) {
            int u = queue.front();
            queue.pop();
            result.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    queue.push(v);
                }
            }
        }

        return result;
    }

private:
    int V;
    vector<int> indegree;
    vector<vector<int>> adj;
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> sorted_order = g.topologicalSort();

    cout << "Thứ tự tô pô:";
    for (int vertex : sorted_order) {
        cout << " " << vertex;
    }
    cout << endl;

    return 0;
}
