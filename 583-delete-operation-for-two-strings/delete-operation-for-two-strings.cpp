class Solution {
public:
    int solve(int i, int j, string& word1, string& word2) {
        if (i <= 0 || j <= 0)
            return 0;
        if (word1[i - 1] == word2[j - 1]) {
            return 1 + solve(i - 1, j - 1, word1, word2);
        } else {
            return max(solve(i - 1, j, word1, word2), solve(i, j - 1, word1, word2));
        }
    }
    int solveMem(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        if (i <= 0 || j <= 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i - 1] == word2[j - 1]) {
            return dp[i][j] = 1 + solveMem(i - 1, j - 1, word1, word2, dp);
        } else {
            return dp[i][j] = max(solveMem(i - 1, j, word1, word2, dp), solveMem(i, j - 1, word1, word2, dp));
        }
    }
    int solveTab(string word1, string word2){
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int lcs = dp[n][m];
        return n + m - 2 * lcs;
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // int ans = solveMem(n, m, word1, word2,dp);
        // return n + m - 2 * ans;
        return solveTab(word1,word2);
    }
};