class Solution {
public:
    string shortestPalindrome(string s) {
 		int n = s.size();
 		string t(s);
 		reverse(t.begin(), t.end());

 		int l = n;
 		for (; l >= 1; --l) {
 			if (s.substr(0, l) == t.substr(n - l, l)) {
 				break;
 			}
 		}
 		return t.substr(0, n - l) + s;
    }
};