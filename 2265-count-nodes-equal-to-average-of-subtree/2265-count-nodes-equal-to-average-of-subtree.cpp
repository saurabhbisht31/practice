class Solution {
public:

    void solve(TreeNode* root, int& sum, int& count, int& ans) {

        if(root == NULL) {
            return;
        }

        int leftsum = 0;
        int leftcount = 0;

        int rightsum = 0;
        int rightcount = 0;

        solve(root->left, leftsum, leftcount, ans);
        solve(root->right, rightsum, rightcount, ans);

        sum = leftsum + rightsum + root->val;
        count = leftcount + rightcount + 1;

        int average = sum / count;

        if(root->val == average) {
            ans++;
        }
    }

    int averageOfSubtree(TreeNode* root) {

        int sum = 0;
        int count = 0;
        int ans = 0;

        solve(root, sum, count, ans);

        return ans;
    }
};