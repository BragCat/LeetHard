class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left = getNearestLower(heights, 0, heights.size(), 1);
        vector<int> right = getNearestLower(heights, heights.size() - 1, -1, -1);
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) { 
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
private:
    vector<int> getNearestLower(vector<int> &heights, int bg, int ed, int delta) {
        vector<int> index(heights.size(), delta == 1 ? 0 : heights.size() - 1);
        stack<int> q;
        for (int i = bg; i != ed; i += delta) {
            while (!q.empty() && heights[q.top()] >= heights[i]) {
                q.pop();
            }
            if (!q.empty()) {
                index[i] = q.top() + delta;
            }
            q.push(i);
        } 
        return index;
    }
};