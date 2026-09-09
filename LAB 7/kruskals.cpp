#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iip;
typedef pair<int, iip> edge;

int findParent(vector<int> &parent, int u) {
    if (parent[u] == u) return u;
    return parent[u] = findParent(parent, parent[u]);
}

void unionSets(vector<int> &parent, vector<int> &rank, int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    if (pu == pv) return;
    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pu] = pv;
        rank[pv]++;
    }
}

int kruskal(vector<edge> &edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    int result = 0;
    for (auto e : edges) {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;
        if (findParent(parent, u) != findParent(parent, v)) {
            unionSets(parent, rank, u, v);
            result += w;
        }
    }
    return result;
}

int main() {
    int n = 4;
    vector<edge> edges;
    edges.push_back({10, {0, 1}});
    edges.push_back({6, {0, 2}});
    edges.push_back({5, {0, 3}});
    
    cout << "MST weight: " << kruskal(edges, n) << endl;

    return 0;
}