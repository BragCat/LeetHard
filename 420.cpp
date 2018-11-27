class Solution {
public:
    int strongPasswordChecker(string s) {
        int len = s.size(), ans = 0;
        int digit = 1, lower = 1, upper = 1;
        vector<int> expand(len, 0);     
        for (int i = 0; i < len;) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit = 0; 
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                lower = 0; 
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                upper = 0; 
            }
            int j = i;
            while (i < len && s[i] == s[j]) {
                ++i; 
            }
            expand[j] = i - j;
        }

        int missing = digit + lower + upper;

        if (len < 6) {
            ans = max(6 - len, missing); 
        } else {
            int tot = 0, overflow = max(0, len - 20);
            for (int res = 0; res < 2; ++res) {
                for (int i = 0; i < len; ++i) {
                    if (expand[i] >= 3 && expand[i] % 3 == res && overflow > 0) {
                        ans += res + 1;
                        overflow -= res + 1;
                        expand[i] -= res + 1;
                    }
                } 
            } 
            if (overflow > 0) {
                ans += overflow;
            }
            for (int i = 0; i < len; ++i) {
                if (expand[i] >= 3 && overflow > 0) {
                    if (expand[i] - 2 > overflow) {
                        expand[i] -= overflow;
                        overflow = 0; 
                    } else {
                        overflow -= expand[i] - 2;
                        expand[i] = 2;
                    }
                } 
                tot += expand[i] / 3;
            }
            ans += max(tot, missing);
        }

        return ans;
    }
};
