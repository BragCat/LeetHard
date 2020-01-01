class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> visited(n, false);
        deque<int> q;
        int ans = 0;
        for (int i : initialBoxes) {
            if (status[i] == 1) {
                q.push_back(i);
            }
            visited[i] = true;
        }
        while (!q.empty()) {
            int b = q.front();
            q.pop_front();
            for (int k : keys[b]) {
                if (status[k] == 0) {
                    status[k] = 1;
                    if (visited[k]) {
                        q.push_back(k);
                    }
                }
            }
            for (int ib : containedBoxes[b]) {
                if (status[ib] == 1 && !visited[ib]) {
                    q.push_back(ib);
                }
                visited[ib] = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (visited[i] && status[i] == 1) {
                ans += candies[i];
            }
        }
        return ans;
    }
};