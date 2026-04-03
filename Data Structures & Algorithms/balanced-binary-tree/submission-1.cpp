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

    int getHeight(TreeNode *root)
    {
        // if there is no root/tree, return 0
        if(!root) return 0;
        // get the height of the children trees
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        // get the balance value by subtracting the left height from the right height.
        int balance = abs(left-right);
        // if the difference between the left and right is greater than 1 return -1
        if(balance > 1 || left == -1 || right == -1) return -1;
        // if not -1 then return the height
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
    
        if(!root) return true;
        return getHeight(root) == -1 ? false: true;

    }
};
