class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        deque<int> flipIndex;
        int ans = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (!flipIndex.empty() && i - flipIndex.front() + 1 > K) {
                flipIndex.pop_front();
            }
            int now = (flipIndex.size() % 2) ^ A[i];
            if (now == 0) {
                if (A.size() - i < K) {
                    return -1;
                }
                flipIndex.push_back(i);
                ++ans;
            }
        }
        return ans;
    }
};