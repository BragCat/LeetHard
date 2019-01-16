class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        map<int, vector<int>> heightState;
        int limit = accumulate(rods.begin(), rods.end(), 0) / 2;
        getHeightState(heightState, rods, 0, 0, 0, limit);
        for (auto it = heightState.rbegin(); it != heightState.rend(); ++it) {
            auto &stateList = it->second;
            for (int i = 0; i < stateList.size(); ++i) {
                for (int j = i + 1; j < stateList.size(); ++j) {
                    if ((stateList[i] & stateList[j]) == 0) {
                        return it->first;
                    }
                }
            }
        }
        return 0;
    }
private:
    void getHeightState(map<int, vector<int>> &heightState, vector<int> &rods, int i, int h, int s, int limit) {
        if (h > limit) {
            return;
        }
        if (i == rods.size()) {
            heightState[h].push_back(s);
            return;
        }
        getHeightState(heightState, rods, i + 1, h, s, limit);
        getHeightState(heightState, rods, i + 1, h + rods[i], s | (1 << i), limit);
    }
};