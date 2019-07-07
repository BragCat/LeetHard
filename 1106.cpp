class Solution {
public:
    bool parseBoolExpr(string expression) {
        if (expression.length() == 1) {
            return expression[0] == 't';
        } 
        if (expression[0] == '!') {
            return !parseBoolExpr(expression.substr(2, expression.length() - 3));
        } else {
            string subs = expression.substr(2, expression.length() - 3);
            vector<string> sube;
            int p = 0;
            while (p < subs.length()) {
                int np = p, cnt = 0;
                while (np < subs.length()) {
                    if (subs[np] == '(') {
                        ++cnt;
                    } else if (subs[np] == ')') {
                        --cnt;
                    }
                    if (cnt == 0 && subs[np] == ',') {
                        break;
                    }
                    ++np;
                }
                sube.push_back(subs.substr(p, np - p));
                p = np + 1;
            }
            bool ans = expression[0] == '&';
            for (auto e : sube) {
                if (expression[0] == '&') {
                    ans = ans && parseBoolExpr(e);
                } else {
                    ans = ans || parseBoolExpr(e);
                }
            }
            return ans;
        }
    }
};