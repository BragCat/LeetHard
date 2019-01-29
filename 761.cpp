class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0;
        vector<string> subs;
        int st = 0;
        for (int i = 0; i < S.length(); ++i) {
            cnt += (S[i] == '1') ? 1 : -1;
            if (cnt == 0) {
                subs.push_back('1' + makeLargestSpecial(S.substr(st + 1, i - st - 1)) + '0');
                st = i + 1;
            }
        }
        sort(subs.begin(), subs.end(), greater<string>());
        return accumulate(subs.begin(), subs.end(), string(""));
    }
};