class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cnt = 0, prevIndex = 0;
        vector<string> ans;
        for (int i = 0; i < words.size(); ++i) {
            if (cnt + (i - prevIndex) + words[i].size() <= maxWidth) {
                cnt += words[i].size();
            } else {
                int space = (i == prevIndex + 1) ? 0 : (maxWidth - cnt) / (i - 1 - prevIndex);
                int extra = (i == prevIndex + 1) ? 0 : (maxWidth - cnt) % (i - 1 - prevIndex);
                string s;
                for (int j = prevIndex; j < i; ++j) {
                    if (j != prevIndex) {
                        s += string(space, ' '); 
                        if (j - prevIndex <= extra) {
                            s += " ";
                        }
                    } 
                    s += words[j];
                }
                while (s.size() < maxWidth) {
                    s += " ";
                }
                ans.push_back(s);
                prevIndex = i;
                cnt = words[i].size();
            }
        }       
    
        string s;
        for (int i = prevIndex; i < words.size(); ++i) {
            if (i != prevIndex) {
                s += " ";
            }
            s += words[i];
        }   
        while (s.size() < maxWidth) {
            s += " ";
        }
        ans.push_back(s);
        return ans;
    }
};
