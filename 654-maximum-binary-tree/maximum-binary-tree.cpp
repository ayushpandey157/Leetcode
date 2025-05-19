/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> s;
        for (auto i : nums) {
            TreeNode* curr = new TreeNode(i);
            while (!s.empty() && s.top()->val < i) {
                curr->left = s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.top()->right = curr;
            }
            s.push(curr);
        }
        while (s.size() > 1) {
            s.pop();
        }
        return s.top();
    }
};