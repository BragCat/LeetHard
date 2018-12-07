class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
    	int n = graph.size();
        vector<vector<int>> f(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            f[i][i] = 0;
            f[0][i] = 2;
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // 0 lost, 1 draw, 2 win
        int result = dfs(graph, f, 1, 2, visited);
        if (result == 1) {
        	return 0;
        } else if (result == 2) {
        	return 1;
        } else {
        	return 2;
        }
    }
    int dfs(vector<vector<int>> &graph, vector<vector<int>> &f, int m, int c, vector<vector<bool>> &visited) {
        if (f[m][c] != -1) {
        	return f[m][c];
        }
        if (visited[m][c]) {
        	return 1;
        }
        visited[m][c] = true;
        
        auto &nextMoveMouse = graph[m];
        auto &nextMoveCat = graph[c];
        for (int i = 0; i < nextMoveMouse.size(); i++) {
            int current = INT_MAX;
            if (nextMoveMouse[i] != c) {
            	for (int j = 0; j < nextMoveCat.size(); j++) {
                	if (nextMoveCat[j] != 0) {
                		current = min(current, dfs(graph, f, nextMoveMouse[i], nextMoveCat[j], visited));
            		}
            	}
            	f[m][c] = max(current, f[m][c]);
            }
        }
        return f[m][c];
    }
};