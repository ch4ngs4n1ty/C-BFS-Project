#include <iostream>
#include <vector>
#include <queue> 
using namespace std;


vector<int> bfs(int start, int finish, const vector<vector<int>>& graph) {

    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    vector<int> parent(n, -1); // 👈 added to trace path

    queue<int> queueGraph;
    queueGraph.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!queueGraph.empty()) {

        int current = queueGraph.front();
        queueGraph.pop();

        if (current == finish) {
            break; // shortest path found
        }

        for (int neighbor : graph[current]) {

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                parent[neighbor] = current; 
                queueGraph.push(neighbor);
            }
        }
    }

    // Reconstruct the path using parent
    vector<int> path;

    if (!visited[finish]) {
        // no path found
        return path;
    }

    for (int cur = finish; cur != -1; cur = parent[cur]) {

        path.push_back(cur);

    }

    reverse(path.begin(), path.end());

    return path;

}

vector<int> bfs_shortest_path(int start, int goal, const vector<vector<int>>& adj) {
    int n = (int)adj.size();
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == goal) break; // earliest hit = shortest in edges

        for (int v : adj[u]) {
            if (dist[v] == -1) {          // not visited
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[goal] == -1) return {};      // no path

    vector<int> path;
    for (int cur = goal; cur != -1; cur = parent[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());    // start -> ... -> goal
    return path;
}


int main() {
    
    int n = 6; // number of nodes

    vector<vector<int>> graph(n);

    // randomized graph data
    // each graph index = node
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    vector<int> path = bfs(1, 5, (graph));

    cout << "Shortest path (" << path.size() - 1 << " edges): ";

    for (int node : path) { 

        cout << node << " ";
        cout << "\n";

    }

}