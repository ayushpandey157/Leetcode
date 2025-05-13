class Solution {
    using ll=long long;
    ll solve(int sum,vector<int> &coins,int amount,vector<ll> &dp){
      if(sum==amount){
        return 0;
      }
      if(dp[sum]!=-1){
        return dp[sum];
      }
      ll take=INT_MAX;
      for(int i=0;i<coins.size();i++){
        if(1ll*sum+1ll*coins[i]<=1ll*amount){
            take=min(take,1+solve(sum+coins[i],coins,amount,dp));
        } 
        else{ 
            break;
            }
      }
      return dp[sum]=take;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());//so apply the break condition while itteating over unlimited supply
       vector<ll> dp(amount+1,-1);
       ll result= solve(0,coins,amount,dp);
        
       return result==INT_MAX?-1:result;
    }
};