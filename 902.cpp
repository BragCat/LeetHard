class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int len = 0;
        string n = to_string(N);
        while (N > 0) {
        	++len;
        	N /= 10;
        }
        int ans = 0, power = D.size();
        for (int i = 1; i < len; ++i) {
        	ans += power;
        	power *= D.size(); 
        }

        ans += dfs(D, n, len, "", 0);
        return ans;
    }

private:
	int dfs(vector<string> &D, string n, int len, string now, int nowLen) {
		if (now != n.substr(0, nowLen)) {
			return static_cast<int>(pow(D.size(), len - nowLen));
		}
		if (nowLen == len) {
			return 1;
		}

		string prefix(n.substr(0, nowLen + 1));
		int ans = 0;
		for (auto digit : D) {
			string candidate = now + digit;
			if (candidate <= prefix) {
				ans += dfs(D, n, len, candidate, nowLen + 1);
			}
		}
		return ans;
	}
};