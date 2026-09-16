class Solution {
public:

    void solve(vector<int>& nums, set<vector<int>>& st,
               vector<int>& ds, vector<bool>& used) {

        if(ds.size() == nums.size()) {
            st.insert(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {

            if(!used[i]) {

                ds.push_back(nums[i]);
                used[i] = true;

                solve(nums, st, ds, used);

                used[i] = false;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<int> ds;
        vector<bool> used(nums.size(), false);
        set<vector<int>> st;

        solve(nums, st, ds, used);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};