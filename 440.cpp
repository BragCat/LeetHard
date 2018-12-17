class Solution {
public:
    int findKthNumber(int n, int k) {
    	int ans = 1;
  		while (k > 1) {
  			int cnt = 0;
  			for (long long st = ans, ed = ans + 1; st <= n; st = st * 10, ed = ed * 10) {
  				cnt += min(ed, static_cast<long long>(n) + 1) - st;
  			}
  			if (cnt < k) {
  				++ans;
  				k -= cnt;
  			} else {
  				ans = ans * 10;
  				--k;	
  			}
  		}      
  		return ans;
    }
};