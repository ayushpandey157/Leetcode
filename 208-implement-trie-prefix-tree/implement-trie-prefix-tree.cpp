class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isterminal;
        TrieNode(char ch){
            data=ch;
            for (int i=0;i<26;i++){
                children[i]=NULL;
            }
            isterminal=false;
        }
};

class Trie {
        TrieNode* root;
public:
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        if (word.size()==0){root->isterminal=true;return;}
        TrieNode* child;
        if (root->children[word[0]-'a']!=NULL){
            child=root->children[word[0]-'a'];
        }
        else {
            child=new TrieNode(word[0]);
            root->children[word[0]-'a']=child;
        }
        insertUtil(child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root, string word){
        if (word.size()==0){return root->isterminal;}
        TrieNode* child;
        if (root->children[word[0]-'a']!=NULL){
            child=root->children[word[0]-'a'];
        }
        else {return false;}
        return searchUtil(child,word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool startwi(TrieNode* root, string word){
        if (word.size()==0){return true;}
        TrieNode* child;
        if (root->children[word[0]-'a']!=NULL){
            child=root->children[word[0]-'a'];
        }
        else {return false;}
        return startwi(child,word.substr(1));
    }

    bool startsWith(string prefix) {
        return startwi(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */