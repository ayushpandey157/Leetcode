class Solution {
public:
    vector<vector<bool>> dp;
    bool isMatch(string s, string p) {
        int s_ = s.size(), p_ = p.size();
        dp.resize(s_ + 1, vector<bool>(p_+1,false));

        dp[0][0] = true;
        for(int i =1;i<=p_;i++){
            if(p[i-1] == '*')dp[0][i] = true; // just a simple hunch that till the string has (...*) n(>=1) stars It can accomodate any string in the data space
            else break;
        }


        for(int i = 1 ;i<=s_;i++){
            for(int j = 1; j<=p_ ; j++){
                if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j]  = dp[i][j] || dp[i-1][j-1]; // normal logic // one optimization can be done, when we encounter a true value for a column of star , mark allthe subsequent rows withcol 1 = true
                }else{
                    if(p[j-1] == '*'){
                        dp[i][j]  = dp[i][j-1] || dp[i-1][j];  // this is valod because either the '*' can accomodate n - other values i.e ... ,p[i-2], p[i-1], or it can be a empty sequence (i.e p[i-2] matches till s[i-2], p[i-1] = "*" can take empty for s).
                    }else{
                        dp[i][j]  = false; // this becomes false because if two patterns at given length don't match the last char then it is invalid
                    }
                }
            }
        }

        return dp[s_][p_];
    }
};