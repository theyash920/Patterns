class Solution {
public:
    int max_sum;

    int dfs(TreeNode* root){
        if(!root) return 0;
        int l = max(dfs(root->left), 0);
        int r = max(dfs(root->right), 0);
        int new_price = root->val + l + r;
        max_sum = max(max_sum, new_price);
        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root){
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
};