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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return root;
        if(root->val == key){
            TreeNode* node2 = root;
            if(node2->right == NULL && node2->left == NULL){
                
                
                return NULL;
                
            }
            else if(node2->right==NULL){
                
                return root->left;
            }else if(node2->left == NULL){
                
                return root->right;
            }else{
                TreeNode* cur = node2;
                cur = cur->left;
                while(cur->right!=NULL){
                    cur = cur->right;
                }
                cur->right = node2->right;
                
                return root->left;
            }
        }
        TreeNode* node = root;
        while(node!=NULL){
            if(node->val > key){
                if(node->left!=NULL && node->left->val == key){
                    TreeNode* node2 = node->left;
                    if(node2->right == NULL && node2->left == NULL){
                        
                        node->left = NULL;
                        return root;
                        
                    }
                    else if(node2->right==NULL){
                        node2 = node2->left;
                        node->left = node2;
                        return root;
                    }else if(node2->left == NULL){
                        node2 = node2->right;
                        node->left = node2;
                        return root;
                    }else{
                        TreeNode* cur = node2;
                        cur = cur->left;
                        while(cur->right!=NULL){
                            cur = cur->right;
                        }
                        cur->right = node2->right;
                        node->left = node2->left;
                        return root;
                    }
                }else{
                    node = node->left;
                }
                
            }else{
                if(node->right!=NULL && node->right->val == key){
                    TreeNode* node2 = node->right;
                    if(node2->right == NULL && node2->left == NULL){
                        
                        node->right = NULL;
                        return root;
                        
                    }
                    else if(node2->right==NULL){
                        node2 = node2->left;
                        node->right = node2;
                        return root;
                    }else if(node2->left == NULL){
                        node2 = node2->right;
                        node->right = node2;
                        return root;
                    }else{
                        TreeNode* cur = node2;
                        cur = cur->left;
                        while(cur->right!=NULL){
                            cur = cur->right;
                        }
                        cur->right = node2->right;
                        node->right = node2->left;
                        return root;
                    }
                }else{
                    node = node->right;
                }
            }
        }return root;
    }
};