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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // get the current node
        TreeNode* curr = root;

        // while the node is not null
        while(curr)
        {   
            // if noth p & q's val is greater than the curr node's we move to inspect the right subtree
            if(p->val > curr->val && q->val > curr->val)
            {
                curr = curr->right;
            }
            // if both p & q's is less than the curr node's we move to inspect the left subtree
            else if(p->val < curr->val && q->val < curr->val)
            {
                curr = curr->left;
            }
            // if p & q's value are not both greater than or less than the curr node's then we've found the LCA
            // because curr is the lowest node where they diverge -> the LCA
            else
            {
                return curr;
            }
        }

        return nullptr;
    }
};
