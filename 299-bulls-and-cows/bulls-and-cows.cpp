class Solution {
public:
    string getHint(string secret, string guess) {
        int m = secret.size();
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> extraSecret;
        unordered_map<char, int> extraGuess;
        for (int i = 0; i < m; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                bool guessMatched = false;
                bool secretMatched = false;
                // current guess matched with a previous secret
                if (extraSecret.find(guess[i]) != extraSecret.end()) {
                    cows++;
                    if (--extraSecret[guess[i]] == 0)
                        extraSecret.erase(guess[i]);
                    guessMatched = true;
                }
                // current secret matched with a previous guess
                if (extraGuess.find(secret[i]) != extraGuess.end()) {
                    cows++;
                    if (--extraGuess[secret[i]] == 0)
                        extraGuess.erase(secret[i]);
                    secretMatched = true;
                } 

                if(!secretMatched){
                    extraSecret[secret[i]]++;
                }
                if(!guessMatched){
                    extraGuess[guess[i]]++;
                }
            }
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};