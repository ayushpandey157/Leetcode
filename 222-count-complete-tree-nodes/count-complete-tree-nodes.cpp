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
    int countNodes(TreeNode* root) {
        // empty tree
        if (!root) return 0;

        int count = 0;

        // lot - any traversal
        queue<TreeNode*> q;

        // initially
        q.push(root);
        
        while (!q.empty()) {
            // access front node
            TreeNode* front = q.front();
            q.pop();

            // increase count
            count++;

            // insert childs of curr level siblings
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }

        return count;
    }
};