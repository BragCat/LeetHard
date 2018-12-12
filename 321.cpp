class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
       	int	len1 = nums1.size(), len2 = nums2.size();
       	vector<int> ans;
       	for (int i = max(0, k - len2); i <= min(k, len1); ++i) {
       		vector<int> subNums1;
       		getSubNums(nums1, i, subNums1);
       		vector<int> subNums2;
       		getSubNums(nums2, k - i, subNums2);
            
       		vector<int> currentAns;
       		mergeSubNums(subNums1, subNums2,currentAns);
       		updateAns(ans, currentAns);
       	}	 
       	return ans;
    }
private:
	void getSubNums(vector<int> &nums, int cnt, vector<int> &subNums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (!subNums.empty() && subNums.back() < nums[i] && subNums.size() - 1 + n - i >= cnt) {
				subNums.pop_back();
			}
			subNums.push_back(nums[i]);
		}
		while (subNums.size() > cnt) {
			subNums.pop_back();
		}
	}

	void mergeSubNums(vector<int> &nums1, vector<int> &nums2, vector<int> &ans) {
		int first = 0, second = 0;
		while (first < nums1.size() && second < nums2.size()) {
			if (nums1[first] > nums2[second]) {
				ans.push_back(nums1[first++]);
			} else if (nums1[first] < nums2[second]) {
				ans.push_back(nums2[second++]);
			} else {
				int i = first, j = second;
				bool firstBigger = true;
				while (i < nums1.size() && j < nums2.size()) {
					if (nums1[i] < nums2[j]) {
						firstBigger = false;
						break;
					} else if (nums1[i] > nums2[j]) {
						break;
					}
					++i, ++j;
				}
				if (i == nums1.size()) {
					ans.push_back(nums2[second++]);
				} else if (j == nums2.size()) {
					ans.push_back(nums1[first++]);
				} else if (firstBigger) {
					ans.push_back(nums1[first++]);
				} else {
					ans.push_back(nums2[second++]);
				}
			}
		}
		while (first < nums1.size()) {
			ans.push_back(nums1[first++]);
		}
		while (second < nums2.size()) {
			ans.push_back(nums2[second++]);
		}
	}

	void updateAns(vector<int> &ans, vector<int> &candidate) {
		if (ans.empty()) {
			ans = candidate;
			return;
		}
		for (int i = 0; i < ans.size(); ++i) {
			if (ans[i] > candidate[i]) {
				return;
			} else if (ans[i] < candidate[i]) {
				ans = candidate;
				return;
			}
		}
	}
};