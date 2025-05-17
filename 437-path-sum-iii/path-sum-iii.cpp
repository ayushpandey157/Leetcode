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

    int helper(TreeNode* root, long long currSum, long long targetSum, unordered_map<long long,long long>& mp) {

        if(!root) {
            return 0;
        }

        currSum += (root->val * 1LL);
        int cnt = mp[currSum - targetSum];

        mp[currSum]++;

        cnt += helper(root->left, currSum, targetSum, mp);
        cnt += helper(root->right, currSum, targetSum, mp);

        mp[currSum]--;
        if(mp[currSum] == 0) {
            mp.erase(currSum);
        }

        return cnt;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long,long long> mp;
        mp[0] = 1;
        return helper(root, 0, targetSum * 1LL, mp);

    }
};