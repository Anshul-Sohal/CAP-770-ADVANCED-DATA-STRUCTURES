#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> createAdjacencyMatrix(int V, int E) {
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    cout << "Enter the edges (vertex pairs):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    return adjMatrix;
}
void printGraph(const vector<vector<int>>& adjMatrix) {
    for (int i = 0; i < adjMatrix.size(); ++i) {
        for (int j = 0; j < adjMatrix[i].size(); ++j) {
            cout << adjMatrix[i][j] << " ";
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
    vector<vector<int>> adjMatrix = createAdjacencyMatrix(V, E);
    cout << "Adjacency matrix representation of the graph:\n";
    printGraph(adjMatrix);
    return 0;
}
