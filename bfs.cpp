#include <iostream>
#include <vector>
#include <queue> 
using namespace std;



int main() {
    
    int n = 6; // number of nodes
    vector<vector<int>> adj(n);

    // example edges (undirected)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {1, 2, 5};
    adj[5] = {3, 4};

    for (int i = 0; i < adj.size(); ++i) {

        cout << "Node " << i << ": ";

        for (int neighbor : adj[i]) cout << neighbor << " ";

            cout << "\n";
    }

}