class Solution {
public:
    bool isAllStars(string&s,int n){
        for(int i = 1; i <= n; i++){
            if(s[i-1] != '*') return false; 
        }
            return true; 
    }
    bool isMatch(string s2, string s1) {
        int n = s1.size(); 
        int m = s2.size(); 
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false)); 
        dp[0][0] = true; 
        for (int j = 1; j <= m; j++) {
            dp[0][j] = false;
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = isAllStars(s1, i);
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j<= m; j++){
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1]; 
                }else if(s1[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else{
                    dp[i][j] = false; 
                }
            }
        }

        return dp[n][m]; 
    }
};