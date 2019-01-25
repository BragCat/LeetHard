class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> odd(n, -1), even(n, -1);
        map<int, int> valueIndex;
        for (int i = n - 1; i >= 0; --i) {
            auto lb = valueIndex.lower_bound(A[i]);
            auto ub = valueIndex.upper_bound(A[i]), prevUb = ub;
            if (lb != valueIndex.begin() && (lb == valueIndex.end() || lb->first > A[i])) {
                --lb;
            }
            if (lb != valueIndex.end() && lb->first <= A[i]) {
                even[i] = lb->second;
            }
            if (prevUb != valueIndex.begin()) {
                --prevUb;
            }
            if (prevUb->first == A[i]) {
                ub = prevUb; 
            } 
            if (ub != valueIndex.end()) {
                odd[i] = ub->second;
            }
            valueIndex[A[i]] = i;
        }
        
        vector<bool> oddSearched(n, false), evenSearched(n, false);
        vector<bool> oddGood(n, false), evenGood(n, false);
        for (int i = 0; i < n; ++i) {
            if (!oddSearched[i]) {
                search(n, i, 1, oddGood, evenGood, oddSearched, evenSearched, odd, even);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (oddGood[i]);
        }
        return ans;
    }
private:
    void search(int n, int i, int s, vector<bool> &oddGood, vector<bool> &evenGood, vector<bool> &oddSearched, vector<bool> &evenSearched, vector<int> &odd, vector<int> &even) {
        if (s % 2 == 1 && oddSearched[i]) {
            return;
        }
        if (s % 2 == 0 && evenSearched[i]) {
            return;
        }
        
        if (i == n - 1) {
            if (s % 2 == 1) {
                oddGood[i] = true;
            } else {
                evenGood[i] = true;
            }
            return;
        }
        
        if (s % 2 == 1) {
            oddSearched[i] = true;
            if (odd[i] != -1) {
                search(n, odd[i], s + 1, oddGood, evenGood, oddSearched, evenSearched, odd, even);
                oddGood[i] = oddGood[i] || evenGood[odd[i]];
            }
        } else {
            evenSearched[i] = true;
            if (even[i] != -1) {
                search(n, even[i], s + 1, oddGood, evenGood, oddSearched, evenSearched, odd, even);
                evenGood[i] = evenGood[i] || oddGood[even[i]];
            }
        }
    }
};