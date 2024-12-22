#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
    vector<vector<int>> adjList;
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void topologicalSort() {
        vector<bool> visited(vertices, false);
        stack<int> stack;

        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        while (!stack.empty()) {
            cout << stack.top() << " ";
            stack.pop();
        }
        cout << endl;
    }

    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }

        stack.push(v);
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort: ";
    g.topologicalSort();

    return 0;
}
