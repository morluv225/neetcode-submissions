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
    int diameterOfBinaryTree(TreeNode* root) {
        // Key thing to remember: 
            // 1. at every node, the longest path thru that node =
            // left subtree height + right subtree height
            // 2. the LONGEST path is not always the DEEPEST/DOWNWARD path
                // the path can go down the left side, then back up, then down the right side (DFS always starts on the left)
                    // the path is allowed to turn at any node as long as you don’t revisit a node.
                /* Key insight: the longest path in a tree is usually: (and also a V shape)
                                deepest node in left subtree
                                            ↓
                                    some ancestor
                                            ↓
                                deepest node in right subtree
                */
        // so we computer the height of every subtree and keep track of the highest diameter
        // can use recursion for this because it uses a stack underneath the hood
        int res = 0;
        dfs(root, res); // dfs returns the height of the tree
        return res; // contains the diameter
    }

private:
    // DFS RETURNS the HEIGHT of the subtree rooted at 'root'
    // and UPDATES res with the max DIAMETER found
    int dfs(TreeNode* root, int& res)
    {
        if(!root) return 0;
        //recursively compute the height of the left subtree
        int left = dfs(root->left, res);
        //recursively compute the height of the right subtree
        int right = dfs(root->right, res);
        // this is the diameter of the current node so update the global max diameter
        res = max(res, left + right);
        // return the height. 1 (for the current node) + the tallest subtree
        return 1 + max(left, right);
    }
};
