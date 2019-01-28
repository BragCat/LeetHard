class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> arr2Index;
        for (int i = 0; i < n; ++i) {
            arr2Index.push_back({arr[i], i});
        }
        sort(arr2Index.begin(), arr2Index.end(), [](auto &a, auto &b) -> bool{
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        });
        vector<int> target(n, -1);
        for (int i = 0; i < n; ++i) {
            target[arr2Index[i].second] = i;
        }
        
        int now = 0, furthest = target[0];
        int ans = 0;
        while (true) {
            while (now < furthest) {
                ++now;
                if (now < n) {
                    furthest = max(furthest, target[now]);
                }
            }
            ++ans;
            ++now;
            if (now < n) {
                furthest = max(now, target[now]);
            } else {
                break;
            }
        }
        return ans;
    }
};