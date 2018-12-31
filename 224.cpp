class Solution {
public:
    int calculate(string s) {
        int n = -1;
        stack<char> op;
        stack<int> num;
        for (auto ch : s) {
            if (ch == ' ') {
                continue;
            } else if (isdigit(ch)) {
                if (n == -1) {
                    n = ch - '0';
                } else {
                    n = n * 10 + ch - '0';
                }
            } else if (ch == '(') {
                op.push(ch);
            } else if (ch == ')') {
                if (n != -1) {
                    num.push(n);
                    n = -1;
                }
                updateStack(op, num);
                op.pop();
            } else {
                if (n != -1) {
                    num.push(n);
                    n = -1;
                }
                updateStack(op, num);
                op.push(ch);
            }
        }
        if (n != -1) {
            num.push(n);
            n = -1;
        }
        updateStack(op, num);
        return num.top();
    }
private:
    void updateStack(stack<char> &op, stack<int> &num) {
        while (!op.empty() && op.top() != '(') {
            char o = op.top();
            op.pop();
            int a = num.top();
            num.pop();
            if (o == '+') {
                num.top() += a;
            } else {
                num.top() -= a;
            }
        }
    }
};