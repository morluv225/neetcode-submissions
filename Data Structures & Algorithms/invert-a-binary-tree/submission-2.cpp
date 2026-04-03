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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr; // if the tree is empty, return null
        queue<TreeNode*> q; // create the queue
        q.push(root); // push the root onto the q

        // standard BFS loop
        while(!q.empty())
        {
            // take the next node from the queue
            // and remove it so we can process it
            TreeNode* node = q.front();
            q.pop(); 
            // Swap its children (left and right pointer)
            swap(node->left, node->right); 
            // add the children back to the queue after they've been swapped so their children can be processed next
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return root;
    }
};
