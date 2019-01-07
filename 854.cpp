class Solution {
public:
    int kSimilarity(string A, string B) {
        assert(A.length() == B.length());
        if (A.length() == 0) {
            return 0;
        }
        if (A[0] == B[0]) {
            return kSimilarity(A.substr(1), B.substr(1));
        } else {
            int ans = MAX_INT;
            string suba = A.substr(1), subb = B.substr(1);
            for (int i = 1; i < A.length(); ++i) {
                if (A[i] == B[0]) {
                    if (B[i] == A[0]) {
                        suba[i - 1] = A[0];
                        return kSimilarity(suba, subb) + 1;
                    }
                    suba[i - 1] = A[0];
                    ans = min(ans, kSimilarity(suba, subb) + 1);
                    suba[i - 1] = A[i];
                }
            }
            return ans;
        }
    }
private:
    const int MAX_INT = ~0u >> 1;
};