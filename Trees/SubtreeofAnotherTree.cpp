class Solution {
public:
    // checks whether two trees are identical
    bool checkif(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;    // both null
        if(!root || !subRoot) return false;   // only one is null

        if(root->val != subRoot->val) return false;

        return checkif(root->left, subRoot->left) && checkif(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot) return false;
        if(checkif(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};