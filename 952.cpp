class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        sort(A.begin(), A.end());

        int maxValue = A.back();
        int maxFactor = round(sqrt(maxValue));
        unordered_map<int, int> valueIndex;
        for (int i = 0; i < n; ++i) {
            f.push_back({i, 1});
            valueIndex[A[i]] = i;
        }

        vector<bool> isPrime(maxValue + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i <= maxValue; ++i) {
            if (isPrime[i]) {
                if (i <= maxFactor) {
                    int j = i + i;
                    while (j <= maxValue) {
                        isPrime[j] = false;
                        j += i;
                    }
                }

                int first = -1;
                int j = i;
                while (j <= maxValue) {
                    auto it = valueIndex.find(j);
                    if (it != valueIndex.end()) {
                        int index = it->second;
                        if (first == -1) {
                            first = index;
                        } else {
                            unionF(first, index);
                        }
                    }
                    j += i;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, f[getF(i)].second);
        }
        return ans;
    }

private:
    vector<pair<int, int>> f;

    void unionF(int a, int b) {
        int indexa = getF(a);
        int indexb = getF(b);
        if (indexa != indexb) {
            f[indexa].second += f[indexb].second;
            f[indexb].second = 0;
            f[indexb].first = indexa;
        }
    }

    int getF(int a) {
        if (f[a].first == a) {
            return a;
        }
        f[a].first = getF(f[a].first);
        return f[a].first;
    }
};
