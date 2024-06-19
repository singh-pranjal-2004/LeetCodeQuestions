/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int k, int &count, int& ans){
        if(root==NULL){
            return;
        }

        solve(root->left, k, count, ans);
        count++;
        if(count==k){
            ans = root->val;
            return;
        }
        solve(root->right, k, count, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans;
        solve(root, k, count, ans);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();