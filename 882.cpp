class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> d = getDistUsingDijkstra(edges, N);
        int ans = 0;
        for (auto &edge : edges) {
            int p = edge[0], q = edge[1], n = edge[2];
            int np = max(0, M - d[p]), nq = max(0, M - d[q]);
            if (np + nq >= n) {
                ans += n;
            } else {
                ans += np + nq;
            }
        }
        for (int i = 0; i < N; ++i) {
            ans += (d[i] <= M);
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
    vector<int> getDistUsingDijkstra(vector<vector<int>> &edges, int N) {
        vector<int> dist(N, MAX_INT);
        dist[0] = 0;
        vector<vector<pair<int, int>>> e(N, vector<pair<int, int>>{});
        for (auto &edge : edges) {
            e[edge[0]].push_back({edge[1], edge[2] + 1});
            e[edge[1]].push_back({edge[0], edge[2] + 1});
        }
        vector<bool> used(N, false);
        while (true) {
            int x = -1;
            for (int i = 0; i < N; ++i) {
                if (!used[i] && (x == -1 || dist[x] > dist[i])) {
                    x = i;
                }
            }
            if (x == -1 || dist[x] == MAX_INT) {
                break;
            }
            used[x] = true;
            for (auto p : e[x]) {
                if (dist[x] + p.second < dist[p.first]) {
                    dist[p.first] = dist[x] + p.second;
                }
            }
        }
        return dist;
    }
};