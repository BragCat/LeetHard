class Node {
public:
    int root, num, malNum;
    Node(): root(-1), num(1), malNum(0) {}
};
class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        sort(initial.begin(), initial.end());
        int ans = -1, ansMalNum = 0, n = graph.size();
        for (auto x : initial) {
            int malCnt = 0;
            vector<Node> f(n, Node());
            for (auto y : initial) {
                f[y].malNum = 1;
            }
            for (int i = 0; i < n; ++i) {
                if (i != x) {
                    for (int j = i + 1; j < n; ++j) {
                        if (j != x && graph[i][j] == 1) {
                            unionSet(f, i, j);
                        }
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i != x) {
                    int r = getRoot(f, i);
                    if (r == i && f[r].malNum > 0) {
                        malCnt += f[r].num;
                    }
                }
            }
            if (ans == -1 || ansMalNum > malCnt) {
                ans = x;
                ansMalNum = malCnt;
            }
        }
        return ans;
    }
private:
    void unionSet(vector<Node> &f, int x, int y) {
        int rx = getRoot(f, x);
        int ry = getRoot(f, y);
        if (rx != ry) {
            if (f[rx].num > f[ry].num) {
                f[ry].root = rx;
                f[rx].num += f[ry].num;
                f[rx].malNum += f[ry].malNum;
                f[ry].num = f[ry].malNum = 0;
            } else {
                f[rx].root = ry;
                f[ry].num += f[rx].num;
                f[ry].malNum += f[rx].malNum;
                f[rx].num = f[rx].malNum = 0;
            }
        }
    }

    int getRoot(vector<Node> &f, int x) {
        if (f[x].root == -1) {
            return x;
        }
        f[x].root = getRoot(f, f[x].root);
        return f[x].root;
    }
};