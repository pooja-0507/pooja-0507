#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Graph {
public:
    Graph(int V);
    void addEdge(int v, int w);
    void saveGraph(const string& filename);

private:
    int V;
    vector<vector<int>> adj;
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::saveGraph(const string& filename) {
    ofstream file(filename);
    for (int v = 0; v < V; ++v) {
        file << v;
        for (auto x : adj[v]) {
            file << " " << x;
        }
        file << "\n";
    }
    file.close();
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.saveGraph("graph.txt");

    return 0;
}
