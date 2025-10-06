#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adj) {
    vis[node] = 1;
    for (int nei : adj[node]) {
        if (!vis[nei]) dfs(nei, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort_DFS(int V, vector<vector<int>>& adj) {
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) dfs(i, vis, st, adj);
    }
    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

vector<int> topoSort_BFS(int V, vector<vector<int>>& adj) {
    vector<int> indeg(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }

    return topo;
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5] = {0, 2};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> ans = topoSort_DFS(V, adj);
    for (int x : ans) cout << x << " ";
}
