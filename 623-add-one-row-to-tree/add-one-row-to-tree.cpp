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
    void qex(vector<TreeNode*> &mp, TreeNode*r, int d, int c){
        if (r==NULL){return;}
        c++;
        if (c==d){mp.push_back(r);return;}
        qex(mp,r->left,d,c);
        qex(mp,r->right,d,c);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1){
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        vector<TreeNode*>mp;
        qex(mp,root,depth,1);
        for (int i=0;i<mp.size();i++){
            if (mp[i]->left){
                TreeNode* temp=new TreeNode(val);
                temp->left=mp[i]->left;
                mp[i]->left=temp;
            }
            else {mp[i]->left=new TreeNode(val);;}
            if (mp[i]->right){
                TreeNode* temp=new TreeNode(val);
                temp->right=mp[i]->right;
                mp[i]->right=temp;
            }
            else {mp[i]->right=new TreeNode(val);}
        }
        return root;
    }
};