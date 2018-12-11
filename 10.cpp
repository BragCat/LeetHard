class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        vector<vector<bool>> f(sLen + 1, vector<bool>(pLen + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= sLen; ++i) {
            for (int j = 0; j <= pLen; ++j) {
                if (!(i == 0 && j == 0)) {
                    if (i == 0) {
                        if (p[j - 1] == '*') {
                            f[i][j] = f[i][j - 1 - 1];
                        } else {
                            f[i][j] = false;
                        }
                    } else if (j == 0) {
                        if (s[i - 1] == '*') {
                            f[i][j] = f[i - 1 - 1][j];
                        } else {
                            f[i][j] = false;
                        }
                    } else if (s[i - 1] == '*') {
                        f[i][j] = f[i - 1 - 1][j];
                        int posPtr = j - 1;
                        while (!f[i][j] && posPtr >= 0 && 
                        	(p[posPtr] == s[i - 1 - 1] || p[posPtr] == '.' || s[i - 1 - 1] == '.')) {

                            f[i][j] = f[i - 1 - 1][posPtr - 1 + 1];
                            --posPtr;
                        }
                    } else if (p[j - 1] == '*') {
                        f[i][j] = f[i][j - 1 - 1];
                        int posPtr = i - 1;
                        while (!f[i][j] && posPtr >= 0 && 
                        	(s[posPtr] == p[j - 1 - 1] || s[posPtr] == '.' || p[j - 1 - 1] == '.')) {

                            f[i][j] = f[posPtr - 1 + 1][j - 1 - 1];
                            --posPtr;
                        }
                    } else if (s[i - 1] == '.' || p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
                        f[i][j] = f[i - 1][j - 1];
                    } else {
                        f[i][j] = false;
                    }
                }
            }
        }
        return f[sLen][pLen]; 
    }
};