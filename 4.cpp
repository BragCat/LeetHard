class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
 		int n1 = nums1.size(), n2 = nums2.size();
		if ((n1 + n2) % 2 == 0) {
			return static_cast<double>(findKth(nums1, nums2, 0, 0, (n1 + n2) / 2) + 
				findKth(nums1, nums2, 0, 0, (n1 + n2) / 2 + 1)) / 2;
		} else {
			return findKth(nums1, nums2, 0, 0, (n1 + n2 + 1) / 2);
		} 		
    }
private:
    int findKth(vector<int> &nums1, vector<int> &nums2, int s1, int s2, int k) {
    	int n1 = nums1.size() - s1, n2 = nums2.size() - s2;
    	if (k > n1 + n2 || k < 1) {
    		return -1;
    	}
    	if (n1 == 0) {
    		return nums2[s2 + k - 1];
    	}
    	if (n2 == 0) {
    		return nums1[s1 + k - 1];
    	}
    	if (k == 1) {
    		return min(nums1[s1], nums2[s2]);
    	}
    	int p1 = k / 2, p2 = k - p1;	
    	if (p1 > n1) {
    		p1 = n1;
    		p2 = k - p1;
    	}
    	if (p2 > n2) {
    		p2 = n2;
    		p1 = k - p2;
    	}
    	if (nums1[s1 + p1 - 1] <= nums2[s2 + p2 - 1]) {
    		return findKth(nums1, nums2, s1 + p1, s2, k - p1);
    	} else {
    		return findKth(nums1, nums2, s1, s2 + p2, k - p2);
    	}
    }
};