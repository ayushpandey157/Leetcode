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
    unordered_map<TreeNode*,int> dp;
    int rob(TreeNode* root) 
    {
        if(root==NULL) return 0;
        if(dp.count(root)) return dp[root];
        int ans=0;
        if(root->left)
        {
            ans+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right)
        {
            ans+=rob(root->right->left)+rob(root->right->right);
        }
        return dp[root]=max(ans+root->val,rob(root->left)+rob(root->right));
    }
};