class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), 
             [](vector<int> &a, vector<int> &b) -> bool {return a[1] < b[1] || (a[1]==b[1] && a[0]<b[0]);});
        int ans = 0, sum = 0;
        priority_queue<int> courseLens;
        for (auto &course : courses) {
            if (sum + course[0] <= course[1]) {
                sum += course[0];
                courseLens.push(course[0]);
            } else if (!courseLens.empty() && courseLens.top() > course[0]) {
                sum -= courseLens.top();
                courseLens.pop();
                courseLens.push(course[0]);
                sum += course[0];
            }
            ans = max(ans, static_cast<int>(courseLens.size()));
        }
        return ans;
    }
};
