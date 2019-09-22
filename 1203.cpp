class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<vector<int>> group_items(m);
        for (int i = 0; i < n; ++i) {
            if (group[i] != -1) {
                group_items[group[i]].push_back(i);
            }
        }
        unordered_map<int, unordered_set<int>> group_pairs; 
        vector<vector<int>> edges(n);
        vector<int> degrees(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < beforeItems[i].size(); ++j) {
                int y = group[i];
                int x = group[beforeItems[i][j]];
                if (x == y) {
                    int q = i, p = beforeItems[i][j];
                    edges[p].push_back(q);
                    ++degrees[q];
                } else if (x == -1) {
                    int p = beforeItems[i][j];
                    for (int q : group_items[y]) {
                        edges[p].push_back(q);
                        ++degrees[q];
                    } 
                } else if (y == -1) {
                    int q = i;
                    for (int p : group_items[x]) {
                        edges[p].push_back(q);
                        ++degrees[q];
                    }
                } else if (group_pairs[x].find(y) == group_pairs[x].end()) {
                    group_pairs[x].insert(y);
                    for (int p : group_items[x]) {
                        for (int q : group_items[y]) {
                            edges[p].push_back(q);
                            ++degrees[q];
                        }
                    }
                }
            }
        }
        vector<int> q;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 0) {
                q.push_back(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            vector<int> nq;
            for (int x : q) {
                for (int y : edges[x]) {
                    --degrees[y];
                    if (degrees[y] == 0) {
                        nq.push_back(y);
                        ans.push_back(y);
                    }
                }
            }
            q.swap(nq);
        }
        if (ans.size() < n) {
            return {};
        }
        for (int i = 0; i < group_items.size(); ++i) {
            group_items[i].clear();
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (group[ans[i]] != -1) {
                group_items[group[ans[i]]].push_back(ans[i]);
            }
        }
        unordered_set<int> inserted;
        vector<int> res;
        for (int i = 0; i < ans.size(); ++i) {
            int x = ans[i];
            if (group[x] == -1) {
                res.push_back(x);
            } else if (inserted.find(group[x]) == inserted.end()) {
                inserted.insert(group[x]);
                for (int y : group_items[group[x]]) {
                    res.push_back(y);
                }
            }
        }
        return res;
    }
};