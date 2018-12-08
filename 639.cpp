class Solution {
public:
    int numDecodings(string s) {
 		int n = s.size();
 		vector<long long> f(n + 1, 0);
 		f[0] = 1;
 		for (int i = 0; i < n; ++i) {
 			if (s[i] == '*') {
 				f[i + 1] = (f[i] * 9) % MODULO;	
 				if (i > 0) {
 					if (s[i - 1] == '*') {
 						f[i + 1] = (f[i + 1] + f[i - 1] * 15 % MODULO) % MODULO;
 					} else if (s[i - 1] == '1') {
 						f[i + 1] = (f[i + 1] + f[i - 1] * 9 % MODULO) % MODULO;
 					} else if (s[i - 1] == '2') {
 						f[i + 1] = (f[i + 1] + f[i - 1] * 6 % MODULO) % MODULO; 
 					}
 				}
 			} else {
 				if (s[i] != '0') {
 					f[i + 1] = (f[i + 1] + f[i]) % MODULO;
 				}
 				if (i > 0) {
 					if (s[i - 1] == '*') {
 						f[i + 1] = (f[i + 1] + f[i - 1]) % MODULO; 
 						if (s[i] <= '6') {
 							f[i + 1] = (f[i + 1] + f[i - 1]) % MODULO;
 						}
 					} else {
 						if (s[i - 1] == '1') {
 							f[i + 1] = (f[i + 1] + f[i - 1]) % MODULO;
 						} else if (s[i - 1] == '2' && s[i] <= '6') {
 							f[i + 1] = (f[i + 1] + f[i - 1]) % MODULO;
 						}
 					}
 				}
 			}
 		}      
 		return f[n];
    }
private:
	const long long MODULO = 1000000007;
};