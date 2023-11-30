#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class EulerianGraph {
public:
    EulerianGraph(int vertices) : V(vertices) {
        graph.resize(V);
    }

    void addEdge(int u, int v) {
        graph[u].push_back(v);
    }

    bool isEulerian() {
        vector<bool> visited(V, false);
        dfsUtil(0, visited);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                return false;
            }
        }

        for (int i = 0; i < V; ++i) {
            if (graph[i].size() != inDegree(i)) {
                return false;
            }
        }

        return true;
    }

    void findEulerianCycle() {
        if (!isEulerian()) {
            cout << "Khong ton tai chu trinh Euler trong do thi\n";
            return;
        }

        stack<int> stack;
        vector<int> circuit;

        int currentVertex = 0;
        stack.push(currentVertex);

        while (!stack.empty()) {
            if (!graph[currentVertex].empty()) {
                stack.push(currentVertex);
                int nextVertex = graph[currentVertex].back();
                graph[currentVertex].pop_back();
                currentVertex = nextVertex;
            } else {
                circuit.push_back(currentVertex);
                currentVertex = stack.top();
                stack.pop();
            }
        }

        reverse(circuit.begin(), circuit.end());

        cout << "Chu trinh Euler: ";
        for (int vertex : circuit) {
            cout << vertex << " - ";
        }
        cout << "\n";
    }

private:
    int V;
    vector<vector<int>> graph;

    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;

        for (int i : graph[v]) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

    int inDegree(int v) {
        int inDegreeCount = 0;
        for (int i = 0; i < V; ++i) {
            for (int j : graph[i]) {
                if (v == j) {
                    ++inDegreeCount;
                }
            }
        }
        return inDegreeCount;
    }
};

int main() {
    EulerianGraph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(1, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    graph.findEulerianCycle();

    return 0;
}
