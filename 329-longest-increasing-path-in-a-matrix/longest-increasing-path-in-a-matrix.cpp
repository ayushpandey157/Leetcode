int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
class Solution {
int fn(int i,int j,vector<vector<int>>&a,vector<vector<int>> &dp){
    int n=a.size();
    int m=a[0].size();
    if(dp[i][j]!=-1)return dp[i][j];
    int val=1;
    for(int k=0;k<4;k++){
        int i2=(i+dx[k]);
        int j2=(j+dy[k]);
        if((i+dx[k])>=0&&(j+dy[k])>=0&&(i+dx[k])<n&&(j+dy[k])<m&&a[i2][j2]>a[i][j]){
            val=max(val,1+fn(i2,j2,a,dp));
        }
    }
    return dp[i][j]=val;
}
public:
    int longestIncreasingPath(vector<vector<int>>& a) {
    int n=a.size();int m=a[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans=max(ans,fn(i,j,a,dp));
        }
    }
    return ans;
    }
};