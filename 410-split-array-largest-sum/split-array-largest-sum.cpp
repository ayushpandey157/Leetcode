class Solution {
public:
    int f(vector<int> &s, int ind , int k,vector<vector<int>> &dp){
        if(ind == s.size()){
            if(k==0) return 0;
            else return INT_MAX;
        }
        if(k<0) return INT_MAX;
        if(dp[ind][k]!=-1) return dp[ind][k];
        int ans = INT_MAX;
        int prev_sm;
        if(ind ==0) prev_sm = 0;
        else prev_sm = s[ind-1]; 
        for(int i = ind;i<s.size();i++){
            ans = min(ans ,max(s[i]-prev_sm,f(s,i+1,k-1,dp)));
        }
        return dp[ind][k] = ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        vector<int> s(n);
        int sm = 0;
        for(int i=0;i<n;i++){
            sm+=nums[i];
            s[i]=sm;
        }
        return f(s,0,k,dp);
    }
};