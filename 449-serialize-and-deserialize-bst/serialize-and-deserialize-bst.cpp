/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        oss << reinterpret_cast<uintptr_t>(root);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        istringstream iss(s);
        uintptr_t address;
        iss >> address;
        return reinterpret_cast<TreeNode*>(address);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;