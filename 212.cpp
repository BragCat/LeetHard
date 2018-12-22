class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        map<char, vector<pair<int, int>>> firstPosition;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                firstPosition[board[i][j]].push_back({i, j});
            }
        }
        
        sort(words.begin(), words.end());
        auto it = unique(words.begin(), words.end());
        words.erase(it, words.end());
        vector<string> ans;
        vector<vector<bool>> searched(m, vector<bool>(n, false));
        for (auto &word : words) {
            auto &fp = firstPosition[word[0]];
            for (auto &p : fp) {
                int x = p.first, y = p.second;
                if (dfs(board, searched, x, y, word, 1)) {
                    ans.push_back(word);
                    break;
                }
            }
        }
        return ans;
    }
private:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, -1, 0, 1};
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &searched, int x, int y, const string &word, int next) {
        if (next == word.size()) {
            return true;
        }
        searched[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && !searched[nx][ny] && board[nx][ny] == word[next]) {
                if (dfs(board, searched, nx, ny, word, next + 1)) {
                    searched[x][y] = false;
                    return true;
                }
            }
        }
        searched[x][y] = false;
        return false;
    }
};