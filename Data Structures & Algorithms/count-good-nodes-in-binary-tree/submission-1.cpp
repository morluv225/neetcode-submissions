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
    int goodNodes(TreeNode* root) {
        // a node is "good" if on the path from the root to that node,
        // no previous node is greater than it
        // so we just need to carry the max value seen so far on the current path
        // we can use dfs for this

        // start dfs from the root and store the root's value as the current max
        return dfs(root, root->val);
    }

    int dfs(TreeNode* node, int maxVal)
    {
        if (!node) return 0;

        // at each node, if node->val >= current maxVal, count it as a good node and increment res
        // and update the maxVal
        int res = (node->val >= maxVal) ? 1: 0;
        maxVal = max(node->val, maxVal);
        // recursively explore with the updated max and sum the counts from left and right
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);

        return res;
    }
};
