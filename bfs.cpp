#include <iostream>
#include <vector>
#include <queue> 
using namespace std;


void bfs(int start, const vector<vector<int>>& graph) {

    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> distance(n, -1);

    queue<int> queueGraph;
    queueGraph.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!queueGraph.empty()) {

        int current = queueGraph.front();

        queueGraph.pop();

        for (int neighbor: graph[current]) {

            if (!visited[neighbor]) {

                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                queueGraph.push(neighbor);

            }
            
        }


    }

    cout << "\n\nNode distances from start:\n";

    for (int i = 0; i < n; i++) {

        cout << "Node " << i << ": " << distance[i] << "\n";

    }   

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

    bfs(1, graph);

}