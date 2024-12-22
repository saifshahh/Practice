#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

class Graph {
private:
    vector<Edge> edges;
    int vertices;

public:
    Graph(int v) {
        vertices = v;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void kruskal() {
        sort(edges.begin(), edges.end());

        DisjointSet ds(vertices);
        vector<Edge> mst;

        for (auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            if (ds.find(u) != ds.find(v)) {
                mst.push_back(edge);
                ds.unite(u, v);
            }
        }

        cout << "Minimum Spanning Tree edges:" << endl;
        for (auto& edge : mst) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskal();

    return 0;
}
