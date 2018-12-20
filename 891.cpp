class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
 		sort(A.begin(), A.end());
 		int n = A.size();
 		long long ans = 0, power = 1;
 		for (int i = 0; i < n; ++i) {
 			ans = (ans + power * A[i] % MODULO) % MODULO; 
 			power = (power * 2) % MODULO;
 		}
 		power = 1;
 		for (int i = 0; i < n; ++i) {
 			ans = (ans + MODULO - power * A[n - i - 1] % MODULO) % MODULO;
 			power = (power * 2) % MODULO;
 		}
 		return ans;
    }
private:
	const int MODULO = 1e9 + 7;
};