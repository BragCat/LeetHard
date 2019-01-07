class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        if (num.length() > 0 && target != MIN_INT) {
            getAns(num, target, "", 0, ans);
        }
        return ans;
    }
private:
    using LL = long long;
    const int MAX_INT = ~0u >> 1;
    const int MIN_INT = -MAX_INT - 1;
    void getAns(string num, int target, string exp, int p, vector<string> &ans) {
        if (p == num.length() - 1) {
            if (isEqualToTarget(exp + num[p], target)) {
                ans.push_back(exp + num[p]);
            }
            return;
        }
        getAns(num, target, exp + num[p], p + 1, ans);
        getAns(num, target, exp + num[p] + '+', p + 1, ans);
        getAns(num, target, exp + num[p] + '-', p + 1, ans);
        getAns(num, target, exp + num[p] + '*', p + 1, ans);
    }
    bool isEqualToTarget(string exp, int target) {
        stack<char> op;
        stack<LL> num;
        LL n = 0;
        for (int i = 0; i < exp.length(); ++i) {
            if (isdigit(exp[i])) {
                if (n == 0 && exp[i] == '0' && i != exp.length() - 1 && isdigit(exp[i + 1])) {
                    return false;
                }
                n = n * 10 + exp[i] - '0';
            } else {
                num.push(n);
                n = 0;
                updateStack(op, num, exp[i]);
                op.push(exp[i]);
            }
        }
        num.push(n);
        n = 0;
        updateStack(op, num, '+');
        return num.top() == target;
    }
    void updateStack(stack<char> &op, stack<LL> &num, char o) {
        while (!op.empty() && isLessEqual(o, op.top())) {
            auto o = op.top();
            op.pop();
            auto a = num.top();
            num.pop();
            if (o == '+') {
                num.top() += a;
            } else if (o == '-') {
                num.top() -= a;
            } else {
                num.top() *= a;
            }
        }
    }
    bool isLessEqual(char o1, char o2) {
        if (o1 == o2) {
            return true;
        } else if (o2 == '*') {
            return true;
        } else if (o1 == '*') {
            return false;
        } else {
            return true;
        }
    }
};