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
    int maxDepth(TreeNode* root) {
       if(!root) return 0; // return null if the tree is empty
       stack<pair<TreeNode*, int>> stack; // create a stack of pairs (the node we're at and its depth)
       stack.push({root, 1}); // push the pair {root,1} as the first node. node = root, depth = 1
       int res = 0;

       while(!stack.empty())
       {
            // get each pair of node/depth and remove from stack to process them
            pair<TreeNode*, int> current = stack.top();
            stack.pop();

            // get the node and the depth from each pair
            TreeNode* node = current.first;
            int depth = current.second;

            // if the node is not empty
            // get the max depth
            // push the current node and its depth onto the stack for both left/right children
            if(node)
            {
                res = max(res, depth);
                stack.push({node->left, depth + 1});
                stack.push({node->right, depth + 1});
            }
       }

       return res;
    }
};
