class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> lines;
        for_each(buildings.begin(), buildings.end(), 
                 [&lines](auto &b) {
                     lines.push_back({1, b[0], b[2]}); 
                     lines.push_back({-1, b[1], b[2]});
                 }
                );
        sort(lines.begin(), lines.end(), 
             [](auto &a, auto &b) -> bool {
                 return a[1]<b[1] || (a[1]==b[1] && a[0]>b[0]) || 
                     (a[1]==b[1] && a[0]==b[0] && (a[0]>0 && a[2]>b[2] || a[0]<0 && a[2]<b[2]));
             }
            );
        
        multiset<int> heights;
        vector<pair<int, int>> ans;
        int maxHeight = 0;
        for (int i = 0; i < lines.size(); ++i) {
            if (lines[i][0] > 0) {
                // in line
                heights.insert(lines[i][2]);
                if (maxHeight < lines[i][2]) {
                    maxHeight = lines[i][2];
                    ans.emplace_back(lines[i][1], maxHeight);
                }
            } else {
                // out line
                heights.erase(heights.find(lines[i][2]));
                int newMaxHeight = heights.empty() ? 0 : *(heights.rbegin());
                if (newMaxHeight < maxHeight) {
                    maxHeight = newMaxHeight;
                    ans.emplace_back(lines[i][1], maxHeight);
                }
            }
        }
        return ans;
    }
};