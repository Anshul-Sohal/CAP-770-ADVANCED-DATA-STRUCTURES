#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>

using namespace std;

// Define a structure for representing edges
struct Edge {
    char to;
    int weight;
    Edge(char t, int w) : to(t), weight(w) {}
};

// Define a structure for representing vertices
struct Vertex {
    vector<Edge> edges;
};

// Dijkstra's algorithm to find shortest path
int dijkstra(vector<Vertex>& graph, char start, char destination) {
    int n = graph.size();
    unordered_map<char, int> dist;
    for (char v = 'a'; v < 'a' + n; ++v) {
        dist[v] = INT_MAX; // Initialize distances to infinity
    }
    dist[start] = 0; // Distance from start to itself is 0

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, start}); // Push the starting vertex with distance 0

    while (!pq.empty()) {
        char u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Stop when the destination vertex is reached
        if (u == destination) {
            return dist[u];
        }

        // Iterate over all neighbors of u
        for (const Edge& e : graph[u - 'a'].edges) {
            char v = e.to;
            int w = e.weight;

            // Relaxation step
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // If destination vertex is not reachable, return -1
    return -1;
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<Vertex> graph(n);

    // Input the edges and their weights
    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < m; ++i) {
        char from, to;
        int weight;
        cin >> from >> to >> weight;
        graph[from - 'a'].edges.emplace_back(to, weight);
    }

    char start, destination;
    cout << "Enter the starting vertex: ";
    cin >> start;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    // Find the shortest distance from the start vertex to the destination vertex
    int shortest_distance = dijkstra(graph, start, destination);

    // Output the shortest distance
    if (shortest_distance != -1) {
        cout << "Shortest distance from vertex " << start << " to vertex " << destination << ": " << shortest_distance << "\n";
    } else {
        cout << "No path found from vertex " << start << " to vertex " << destination << "\n";
    }

    return 0;
}
