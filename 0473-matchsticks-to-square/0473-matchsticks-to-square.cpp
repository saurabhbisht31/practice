class Solution {
public:

    bool solve(vector<int>& matchsticks, int idx,
               int s1, int s2, int s3, int s4, int q) {

        if (idx == matchsticks.size()) {
            return s1 == q &&
                   s2 == q &&
                   s3 == q &&
                   s4 == q;
        }

        int x = matchsticks[idx];
        if (s1 + x <= q) {
            if (solve(matchsticks, idx + 1,
                      s1 + x, s2, s3, s4, q)) {
                return true;
            }
        }
        if (s2 + x <= q) {
            if (solve(matchsticks, idx + 1,
                      s1, s2 + x, s3, s4, q)) {
                return true;
            }
        }
        if (s3 + x <= q) {
            if (solve(matchsticks, idx + 1,
                      s1, s2, s3 + x, s4, q)) {
                return true;
            }
        }

        if (s4 + x <= q) {
            if (solve(matchsticks, idx + 1,
                      s1, s2, s3, s4 + x, q)) {
                return true;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {

        int sum = 0;

        for (int x : matchsticks) {
            sum += x;
        }

        if (sum % 4 != 0) {
            return false;
        }

        int q = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > q) {
            return false;
        }

        return solve(matchsticks, 0, 0, 0, 0, 0, q);
    }
};