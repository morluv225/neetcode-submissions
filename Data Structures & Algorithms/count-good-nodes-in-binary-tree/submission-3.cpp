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
        if(!root) return 0;
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty())
        {
            pair<TreeNode*, int> curr = q.front();
            q.pop();
            TreeNode* node = curr.first;
            int maxVal = curr.second;

            if(node->val >= maxVal)
            {
                res++;
            }
            if(node->left)
            {
                q.push({node->left, max(maxVal, node->val)});
            }
            if(node->right)
            {
                q.push({node->right, max(maxVal, node->val)});
            }
        }
    return res;
    }
};
