class Solution {
public:
    int longestValidParentheses(string s) {
    	stack<pair<char, int>> chStack;
    	for (int i = 0; i < s.size(); ++i) {
    		if (chStack.empty()) {
    			chStack.push({s[i], i});
    		} else if (s[i] == ')' && chStack.top().first == '(') {
    			chStack.pop();
    		} else {
    			chStack.push({s[i], i});
    		}
    	}

    	int ans = 0;
    	int r = s.size();
    	if (chStack.empty()) {
    		ans = r;
    	} else {
    		while (!chStack.empty()) {
    			int l = chStack.top().second;
    			chStack.pop();
    			ans = max(ans, r - l - 1);
    			r = l;
    		}
    		ans = max(ans, r);
    	}
    	return ans;
    }
};