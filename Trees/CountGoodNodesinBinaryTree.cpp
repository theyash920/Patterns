class Solution {
public:
    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
    int helper(TreeNode* root, int curMax){
        if(root == NULL){
            return 0;
        }
        int rootAnswer = 0;
        if(root->val >= curMax){
            rootAnswer = 1;
            curMax = root->val;
        }
        int lans = helper(root->left, curMax);
        int rans = helper(root->right, curMax);
        return lans + rans + rootAnswer;
    }
};