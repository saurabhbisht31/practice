class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            unordered_set<int> vis;

            int j = i;

            bool forward = nums[j] > 0;

            while (!vis.count(j)) {
                if ((nums[j] > 0) != forward) {
                    break;
                }

                vis.insert(j);

                j = ((j + nums[j]) % n + n) % n;
            }

            if (vis.count(j)) {
                int next = ((j + nums[j]) % n + n) % n;

                if (next != j) {
                    return true;
                }
            }
        }

        return false;
    }
};