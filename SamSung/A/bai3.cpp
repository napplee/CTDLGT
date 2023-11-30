#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Custom comparator for pairs to handle unordered_map key comparison
struct PairHash {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        // Combine hash values without considering order
        return hash1 ^ hash2;
    }
};

struct PairEqual {
    template <class T1, class T2>
    bool operator() (const pair<T1, T2>& p1, const pair<T1, T2>& p2) const {
        return (p1.first == p2.first && p1.second == p2.second) ||
               (p1.first == p2.second && p1.second == p2.first);
    }
};

// Function to count parallel edges in a graph
int countParallelEdges(const vector<pair<int, int>>& edges) {
    unordered_map<pair<int, int>, int, PairHash, PairEqual> edgeCount;

    // Count the number of edges between each pair of vertices
    for (const auto& edge : edges) {
        edgeCount[edge]++;
    }

    // Count the number of parallel edges
    int parallelEdges = 0;
    for (const auto& it : edgeCount) {
        if (it.second > 1) {
            parallelEdges += it.second - 1;
        }
    }

    return parallelEdges;
}

int main() {
    // Example usage
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {1, 2}, {3, 4}, {2, 3}, {1, 4}, {2, 1}};

    int parallelEdges = countParallelEdges(edges);

    cout << "Number of parallel edges: " << parallelEdges << endl;

    return 0;
}
