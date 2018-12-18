class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
 		vv nexts;      
 		for (auto &word : wordDict) {
 			nexts.push_back(getNext(word));
 		}

		vv matchs = vv(s.size(), vector<int>());
 		for (int i = 0; i < wordDict.size(); ++i) {
 			getMatch(s, wordDict[i], i, nexts[i], matchs);
 		}

 		vector<vector<string>> results(s.size(), vector<string>{"0"});
 		dfs(matchs, wordDict, 0, results);

 		return vector<string>(results[0].begin() + 1, results[0].end());
    }
private:	
	using vv = vector<vector<int>>;
	vector<int> getNext(string word) {
		int n = word.size();
		vector<int> next;
		int j = -1;
		next.push_back(-1);
		for (int i = 1; i < n; ++i) {
			while (j != -1 && word[i] != word[j + 1]) {
				j = next[j];
			}
			if (word[i] == word[j + 1]) {
				next.push_back(++j);
			} else {
				next.push_back(-1);
			}
		}
		return next;
	}

	void getMatch(const string s, const string word, int index, vector<int> &next, vv &matchs) {
		int j = -1;
		for (int i = 0; i < s.size(); ++i) {
			while (j != -1 && s[i] != word[j + 1]) {
				j = next[j];
			}
			if (s[i] == word[j + 1]) {
				++j;
			}
			if (j == word.size() - 1) {
				matchs[i - word.size() + 1].push_back(index);
				j = next[j];
			} 
		}
	}

	void dfs(const vv &matchs, const vector<string> &wordDict, 
		int pos, vector<vector<string>> &results) {

		if (results[pos][0] == "1") {
			return;
		}

		for (int index : matchs[pos]) {
			int nextPos = pos + wordDict[index].size();
			if (nextPos != matchs.size()) {
				dfs(matchs, wordDict, nextPos, results);
				for (int i = 1; i < results[nextPos].size(); ++i) {
					results[pos].push_back(wordDict[index] + " " + results[nextPos][i]);
				}
			} else {
				results[pos].push_back(wordDict[index]);
			}
		}
		results[pos][0] = "1";
	}
};