class Solution {
public:
    int minCut(string s) {
    	int n = s.size();
    	vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    	for (int i = 0; i < n; ++i) {
    		getPalin(s, i, i, isPalin);
    		getPalin(s, i, i + 1, isPalin);
    	}

    	vector<int> f(n + 1, MAX_INT);
    	f[0] = 0;
    	for (int i = 0; i < n; ++i) {
    		int index = i + 1;
    		for (int j = 0; j < index; ++j) {
    			if (f[j] != MAX_INT && isPalin[j][i]) {
    				f[index] = min(f[index], f[j] + 1);
    			}
    		}
    	}
    	return f[n] - 1;
    }
private:
	const int MAX_INT = ~0u >> 1;
	void getPalin(const string &s, int l, int r, vector<vector<bool>> &isPalin) {
		while (l >= 0 && r < s.size()) {
			if (s[l] != s[r]) {
				break;
			}
			isPalin[l][r] = true;
			--l, ++r;
		}
	}
};