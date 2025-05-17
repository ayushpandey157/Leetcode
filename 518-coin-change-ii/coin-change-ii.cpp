class Solution {
public:
    int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if(target==0) return 1;
        if(ind==0){
            if(target==0 || target%coins[ind]==0) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nt = solve(ind-1, target, coins, dp);
        int t = coins[ind]<=target? solve(ind, target-coins[ind], coins, dp):0;
        return dp[ind][target] = t+nt;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};