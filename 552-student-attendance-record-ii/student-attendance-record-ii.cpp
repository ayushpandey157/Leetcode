class Solution {
public:
    int MOD = 1e9+7;
    int solve(int n, int AC, int LC, vector<vector<vector<int>>> &dp){
        if(AC == 2 || LC == 3) return 0;
        if(n == 0) return 1;
        if(dp[n][AC][LC] != -1) return dp[n][AC][LC];
        long long int ans = ( ( (1LL * solve(n-1, AC+1, 0, dp)) + 
                        (1LL * solve(n-1, AC, LC+1, dp)) + 
                        (1LL * solve(n-1, AC, 0, dp)) ) % MOD );
        return dp[n][AC][LC] = ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(n, 0, 0, dp);
    }
};