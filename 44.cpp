class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        vector<vector<bool>> f(slen + 1, vector<bool>(plen + 1, false));   
        vector<bool> preS(plen + 1, false); 
        f[0][0] = true;
        preS[0] = true;
        for (int i = 0; i <= slen; ++i) {
            for (int j = 1; j <= plen; ++j) {
                f[i][j] = (preS[j - 1] && p[j - 1] == '*') 
                        || (i > 0 && f[i - 1][j - 1] && p[j - 1] == '?') 
                        || (i > 0 && f[i - 1][j - 1] && s[i - 1] == p[j - 1]);
                preS[j] = preS[j] || f[i][j];
            } 
        }
        return f[slen][plen];
    }
};
