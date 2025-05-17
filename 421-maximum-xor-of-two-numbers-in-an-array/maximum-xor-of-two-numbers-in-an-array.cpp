
struct trie{
    trie* children[2];
    trie(){
        children[0]=NULL;
        children[1]=NULL;
    }
};
class TrieNode{
    private:
        trie* root;
    public:
        TrieNode(){
            root=new trie();
        }
    
    void insert(int num){

        trie* curr = root;
        
        for(int i=31;i>=0;i--){

            int bit=(num>>i)&1;
            if(curr->children[bit] == NULL){
                curr->children[bit]=new trie();
            }
            curr=curr->children[bit];
        }
    }
    
    int max_xor(int num){

        trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){

            int bit=(num>>i)&1;
            if(curr->children[!bit]){
                ans+=(1<<i);
                curr=curr->children[!bit];
            }
            else{
                curr=curr->children[bit];
            }
        }
        return ans;
    }   
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {

        int max_ans = 0;
        int n = nums.size();
        int ind = nums.size()-1;
        int maxEl = *max_element(nums.begin(),nums.end());
        if(maxEl == 0) return 0;
        int maxi = floor(log2(maxEl));

        vector<int>temp;

        for(int i = nums.size()-1 ; i>=0 ;i--){
            if( floor(log2(nums[i])) == maxi ){
                temp.push_back(i);
            }
        }
        
        TrieNode* t = new TrieNode();
        
        for(int i=0;i<n;i++){
            t->insert(nums[i]);
        }
        for(int i = 0; i< temp.size();i++){ 
            max_ans = max(max_ans,t->max_xor(nums[temp[i]]));
        }

        return max_ans;
    }
};
