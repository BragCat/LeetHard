class Solution {
public:
    int superEggDrop(int K, int N) {
    	vector<vector<int>> f(MAX_DROP, vector<int>(K + 1, 0));
    	int ans = 0;
    	while (f[ans][K] < N) {
    		++ans;
    		for (int i = 1; i <= K; ++i) {
    			f[ans][i] = f[ans - 1][i - 1] + f[ans - 1][i] + 1;
    		}
    	}
    	return ans;
    }
private:
	const int MAX_DROP = 10001;
};