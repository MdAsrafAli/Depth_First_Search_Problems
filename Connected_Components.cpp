#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis) {
    vis[node] = 1;
    for (int nei : adj[node]) {
        if (!vis[nei]) dfs(nei, adj, vis);
    }
}

int countComponents(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis);
            count++;
        }
    }
    return count;
}

int main() {
    int V = 6;
    vector<int> adj[V];
    adj[0] = {1};
    adj[1] = {0, 2};
    adj[2] = {1};
    adj[3] = {4};
    adj[4] = {3, 5};
    adj[5] = {4};

    cout << countComponents(V, adj); // Output: 2
}
