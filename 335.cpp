class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
        if (n <= 3) {
            return false;
        }

        bool outer = true;
        if (x[2] <= x[0]) {
	        outer = false;
        }

        for (int i = 3; i < n; i++) {
            if (!outer) {
		        if (x[i] >= x[i - 2]) {
			        return true;
		        }
	        } else {
		        if (x[i] <= x[i - 2]) {
			        outer = false;
			        if (x[i - 2] - x[i - 4] <= x[i]) {
				        x[i - 1] = x[i - 1] - x[i - 3];
			        }
		        }
	        }
        }
        return false;
    }
};
