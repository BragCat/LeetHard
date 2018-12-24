class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        if (A.size() < 3) {
            return {-1, -1};
        }
        vector<int> gap;
        vector<int> index;
        int preIndex = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == 1) {
                if (preIndex == -1) {
                    preIndex = i;
                } else {
                    gap.push_back(i - preIndex);
                    index.push_back(preIndex);
                    preIndex = i;
                }
            }
        }
        
        if (preIndex != -1) {
            gap.push_back(A.size() - preIndex);
            index.push_back(preIndex);
        } else {
            return {0, 2};
        }
        
        if (gap.size() % 3 != 0) {
            return {-1, -1};
        }
        
        int i = index.size() / 3 - 1, j = index.size() / 3 * 2;
        if (gap[i] < gap.back() || gap[j - 1] < gap.back()) {
            return {-1, -1};
        } 
        
        int p1 = 0, p2 = i + 1, p3 = j;
        while (p3 < index.size() - 1) {
            if (gap[p1] != gap[p2] || gap[p1] != gap[p3]) {
                return {-1, -1};
            }
            ++p1, ++p2, ++p3;
        }
        return {index[i] + gap.back() - 1, index[j - 1] + gap.back()};
    }
};