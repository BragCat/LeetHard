class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	int n = prices.size();
    	if (n == 0) {
    		return 0;
    	} 
    	k *= 2;
    	if (k > n) {
    		k = n;
    	}
    	vector<int> f[2] = {vector<int>(n + 1, MIN_INT), vector<int>(n + 1, MIN_INT)};
    	vector<int> g[2] = {vector<int>(n + 1, MIN_INT), vector<int>(n + 1, MIN_INT)};
    	f[0][0] = 0;
    	for (int day = 1; day <= n; ++day) {
    		g[0][day] = 0;
    	}
    	int t = 0, ans = 0;
 		for (int times = 1; times <= k; ++times) {
 			t ^= 1;
 			f[t] = vector<int>(n + 1, MIN_INT);
 			g[t] = vector<int>(n + 1, MIN_INT);
 			for (int day = times; day <= n; ++day) {
 				int i = day - 1;
 				int newProfit = (times % 2 == 1) ? -prices[i] : prices[i];
 				if (g[t ^ 1][day] != MIN_INT) {
 					f[t][day] = g[t ^ 1][day] + newProfit;
 				}
 				ans = max(ans, f[t][day]);
 				g[t][day] = max(g[t][day - 1], f[t][day - 1]);
 			}
 		}

 		return ans;
    }
private:
	const int MIN_INT = -static_cast<int>(~0u >> 1) - 1;
};