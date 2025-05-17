class Solution {
public:
    unordered_set<string> st;
    unordered_map<string, bool> memo;

    bool canForm(string word) {
        if (memo.count(word)) return memo[word];
        for (int i = 1; i < word.size(); ++i) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);

            if (st.count(prefix) && (st.count(suffix) || canForm(suffix))) {
                return memo[word] = true;
            }
        }
        return memo[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        for (string& word : words) {
            st.insert(word);
        }

        for (string& word : words) {
            st.erase(word);  // avoid using the word itself
            if (canForm(word)) {
                result.push_back(word);
            }
            st.insert(word);  // add it back
        }

        return result;
    }
};