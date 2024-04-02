#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 100000;
vector<pii> graph[MAXN + 1];
int dist[MAXN + 1];

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        if (current_distance > dist[current_vertex]) {
            continue;
        }

        for (auto edge : graph[current_vertex]) {
            int to = edge.first;
            int weight = edge.second;

            if (current_distance + weight < dist[to]) {
                dist[to] = current_distance + weight;
                pq.push({dist[to], to});
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        dist[i] = INT_MAX;
    }

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    cin >> s >> t;
    dijkstra(s);

    if (dist[t] == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << dist[t] << endl;
    }

    return 0;
}