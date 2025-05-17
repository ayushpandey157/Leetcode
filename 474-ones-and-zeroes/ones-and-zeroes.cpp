class Solution {
public:
int dp[601][101][101];
int solve(int start,int maxzero,int maxone,vector<pair<int,int>>&v)
{
    if(start>=v.size())
    return 0;
    if(dp[start][maxzero][maxone]!=-1)
    return dp[start][maxzero][maxone];
    int taken=0,not_taken=0;
    if(maxzero>=v[start].first && maxone>=v[start].second)
    {
        taken=1+solve(start+1,maxzero-v[start].first,maxone-v[start].second,v);
    }
    not_taken=solve(start+1,maxzero,maxone,v);
    return dp[start][maxzero][maxone]=max(taken,not_taken);
}
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>v;
        for(int i=0;i<strs.size();i++)
        {
            int zero=0;
            int one=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0')
                zero++;
                else
                one++;
            }
            v.push_back({zero,one});
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,v);
    }
};