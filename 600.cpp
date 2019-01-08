class Solution {
public:
    int findIntegers(int num) {
        if (num == 1) {
            return 2;
        }
        string snum = getBinaryString(num);
        int ans = getAnsFromScratch(snum.length() - 1);
        ans += getAnsFromPrefix(snum, "1");
        return ans;
    }
private:
    string getBinaryString(int num) {
        string s;
        while (num > 0) {
            s = ((num % 2) ? "1" : "0") + s;
            num /= 2;
        }
        return s;
    }
    int getAnsFromScratch(int m) {
        // dp to get ans
        vector<vector<int>> f(m + 1, vector<int>(m + 1, 0)), g(m + 1, vector<int>(m + 1, 0));
        f[1][0] = g[1][1] = 1;
        for (int i = 2; i <= m; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (2 * j <= i + 1) {
                    f[i][j] = f[i - 1][j] + g[i - 1][j];
                    if (j != 0) {
                        g[i][j] = f[i - 1][j - 1]; 
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; ++i) {
            ans += f[m][i] + g[m][i];
        }
        
        return ans;
    }
    
    int getAnsFromPrefix(string s, string p) {
        if (p.length() == s.length()) {
            return 1;
        }
        if (p != s.substr(0, p.length())) {
            return getAnsFromScratch(s.length() - p.length());
        }
        int ans = getAnsFromPrefix(s, p + "0");
        if (s[p.length()] == '1' && p.back() != '1') {
            ans += getAnsFromPrefix(s, p + "1");
        }
        return ans;
    }
};