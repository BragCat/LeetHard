class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> cnt(N, 1), ans(N, 0);
        vector<vector<int>> e(N, vector<int>{});
        for (int i = 0; i < edges.size(); ++i) {
            e[edges[i][0]].push_back(edges[i][1]);
            e[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(N, false);
        ans[0] = getCnt(0, cnt, e, visited);
        for (int i = 0; i < N; ++i) {
            visited[i] = false;
        }
        solveAns(0, ans, cnt, e, visited);
        return ans;
    }
private:
    int getCnt(int node, vector<int> &cnt, vector<vector<int>> &e, vector<bool> &visited) {
        visited[node] = true;
        int sumd = 0;
        for (int i = 0; i < e[node].size(); ++i) {
            if (!visited[e[node][i]]) {
                sumd += getCnt(e[node][i], cnt, e, visited) + cnt[e[node][i]];
                cnt[node] += cnt[e[node][i]];
            }
        }
        return sumd;
    }
    void solveAns(int node, vector<int> &ans, vector<int> &cnt, vector<vector<int>> &e, vector<bool> &visited) {
        visited[node] = true;
        int N = ans.size();
        for (int i = 0; i < e[node].size(); ++i) {
            int nNode = e[node][i];
            if (!visited[nNode]) {
                ans[nNode] = ans[node] + (N - cnt[nNode]) - cnt[nNode];
                solveAns(nNode, ans, cnt, e, visited);
            }
        }
    }
};