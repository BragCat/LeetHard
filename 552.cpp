class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) {
            return 3;
        }
        
        vector<int> A(n, 0), P(n, 0), L(n, 0);
        
        P[0] = 1;
        L[0] = 1;
        L[1] = 3;
        A[0] = 1;
        A[1] = 2;
        A[2] = 4;
        
        for (int i = 1; i < n; i++) {
            A[i - 1] %= MODULO;
            P[i - 1] %= MODULO;
            L[i - 1] %= MODULO;
            
            P[i] = ((A[i - 1] + P[i - 1]) % MODULO + L[i - 1]) % MODULO;
            
            if (i > 1) {
                L[i] = ((A[i - 1] + P[i - 1]) % MODULO + (A[i - 2] + P[i - 2]) % MODULO) % MODULO;
            }
            
            if (i > 2) {
                A[i] = ((A[i - 1] + A[i - 2]) % MODULO + A[i - 3]) % MODULO;
            }
        }
        
        return ((A[n - 1] % MODULO + P[n - 1] % MODULO) % MODULO + L[n - 1] % MODULO) % MODULO;
    }
private:
    const int MODULO = 1e9 + 7;
};