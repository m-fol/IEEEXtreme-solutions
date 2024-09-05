#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int getInputFromIndex(vector<int>& input, int& idx) {
    return input[idx++];
}

vector<vector<int>> bfs(int n, vector<vector<int>>& roads) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    for (auto& road : roads) {
        int u = road[0] - 1, v = road[1] - 1;
        dist[u][v] = dist[v][u] = 1;
    }
    for (int start = 0; start < n; ++start) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = 0; next < n; ++next) {
                if (dist[curr][next] == 1 && !visited[next]) {
                    dist[start][next] = dist[start][curr] + 1;
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    return dist;
}

pair<int, pair<int, int>> find_min_max_travel_time(vector<vector<int>>& dist1, vector<vector<int>>& dist2) {
    int n1 = dist1.size();
    int n2 = dist2.size();
    int min_max_time = INT_MAX;
    pair<int, int> best_bridge = {INT_MAX, INT_MAX};
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            int max_time = 0;
            for (int u = 0; u < n1; ++u) {
                for (int v = 0; v < n2; ++v) {
                    if (dist1[u][i] != INT_MAX && dist2[j][v] != INT_MAX) {
                        max_time = max(max_time, dist1[u][i] + 1 + dist2[j][v]);
                    }
                }
            }
            if (max_time < min_max_time || (max_time == min_max_time && make_pair(i + 1, j + 1) < best_bridge)) {
                min_max_time = max_time;
                best_bridge = {i + 1, j + 1};
            }
        }
    }
    return {min_max_time, best_bridge};
}

int main() {
    vector<int> input = {
        3,
        8,
        1, 2,
        2, 3,
        3, 4,
        4, 5,
        2, 6,
        3, 7,
        4, 8,
        4,
        1, 2,
        1, 3,
        1, 4,
        7,
        1, 2,
        2, 3,
        3, 4,
        5, 6,
        6, 3,
        3, 7,
        4,
        1, 2,
        2, 3,
        3, 4,
        2,
        1, 2,
        2,
        2, 1
    };

    int idx = 0;
    int t = getInputFromIndex(input, idx);

    while (t--) {
        int n1 = getInputFromIndex(input, idx);
        vector<vector<int>> roads1;
        for (int i = 0; i < n1 - 1; ++i) {
            int u = getInputFromIndex(input, idx);
            int v = getInputFromIndex(input, idx);
            roads1.push_back({u, v});
        }

        int n2 = getInputFromIndex(input, idx);
        vector<vector<int>> roads2;
        for (int i = 0; i < n2 - 1; ++i) {
            int u = getInputFromIndex(input, idx);
            int v = getInputFromIndex(input, idx);
            roads2.push_back({u, v});
        }

        vector<vector<int>> dist1 = bfs(n1, roads1);
        vector<vector<int>> dist2 = bfs(n2, roads2);

        auto result = find_min_max_travel_time(dist1, dist2);

        cout << result.first << endl;
        cout << result.second.first << " " << result.second.second << endl;
    }

    return 0;
}
