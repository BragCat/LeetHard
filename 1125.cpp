class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        vector<int> skills;
        for (int i = 0; i < people.size(); ++i) {
            int skill = 0;
            for (auto &s : people[i]) {
                for (int j = 0; j < req_skills.size(); ++j) {
                    if (s == req_skills[j]) {
                        skill |= 1 << j;
                        break;
                    }
                }
            }
            skills.push_back(skill);
        }
        int sufficient = (1 << req_skills.size()) - 1;
        vector<vector<int>> f(people.size() + 1, vector<int>(sufficient + 1, MAX_INT));
        vector<vector<pair<int, int>>> g(people.size() + 1, vector<pair<int, int>>(sufficient + 1, make_pair(-1, -1)));
        f[0][0] = 0;
        for (int i = 0; i < people.size(); ++i) {
            for (int j = 0; j <= sufficient; ++j) {
                if (f[i][j] != MAX_INT) {
                    if (f[i + 1][j] > f[i][j]) {
                        f[i + 1][j] = f[i][j];
                        g[i + 1][j] = {i, j};
                    }
                    if (f[i + 1][j | skills[i]] > f[i][j] + 1) {
                        f[i + 1][j | skills[i]] = f[i][j] + 1;
                        g[i + 1][j | skills[i]] = {i, j};
                    }
                }
            }
        }
        int i = people.size(), j = sufficient;
        vector<int> ans;
        while (i != -1) {
            int ni = g[i][j].first, nj = g[i][j].second;
            if (nj != j && nj != -1) {
                ans.push_back(ni);
            }
            i = ni, j = nj;
        }
        return ans;
    }
private:
    const int MAX_INT = ~0u >> 1;
};