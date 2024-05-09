#include <iostream>
#include <vector>
using namespace std;
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    vector<vector<int>> adj(V);
    cout << "Enter the edges (vertex pairs):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    cout << "Adjacency list representation of the graph:\n";
    printGraph(adj);
    return 0;
}
