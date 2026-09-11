class Solution {
public:

    void solve(vector<int>& digits, set<int>& st,
               vector<bool>& used, int temp, int count) {


        if (count == 3) {
            if (temp % 2 == 0) {
                st.insert(temp);
            }
            return;
        }

        for (int i = 0; i < digits.size(); i++) {

            if (used[i])
                continue;

            if (count == 0 && digits[i] == 0)
                continue;


            used[i] = true;

            solve(digits, st, used,
                  temp * 10 + digits[i],
                  count + 1);
            used[i] = false;
        }
    }

    int totalNumbers(vector<int>& digits) {

        set<int> st;
        vector<bool> used(digits.size(), false);

        solve(digits, st, used, 0, 0);

        return st.size();
    }
};