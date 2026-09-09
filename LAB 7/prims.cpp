#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iip;

int prim(vector<vector<iip>> &graph, int n) {
    priority_queue<iip, vector<iip>, greater<iip>> pq;
    vector<bool> inMST(n, false);
    int result = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
        iip p = pq.top();
        pq.pop();

        int u = p.second;
        int w = p.first;

        if (inMST[u]) continue;

        result += w;
        inMST[u] = true;

        for (auto s : graph[u]) {
            int v = s.first;
            int weight = s.second;
            if (!inMST[v]) pq.push({weight, v});
        }
    }

    return result;
}

int main() {
    int n = 4;
    vector<vector<iip>> graph(n, vector<iip>());
    graph[0].push_back({1, 10});
    graph[0].push_back({2, 6});
    graph[0].push_back({3, 5});

    cout << "MST weight: " << prim(graph, n) << endl;

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(20);
    pq.push(2);
    pq.push(10);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    return 0;
} 