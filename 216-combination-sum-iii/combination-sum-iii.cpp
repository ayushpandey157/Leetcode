class Solution {
public:
    void solve(unordered_map<int,int> &mp, int target, int currsum, vector<vector<int>>&ans, vector<int>path, int k){
        if (path.size()>k){return;}
        if (path.size()==k){
            if (currsum==target){
                sort(path.begin(),path.end());
                ans.push_back(path);return;
            }
            else {return;}
        }
        for (auto &it:mp){
            if (it.second>0){
                if (currsum+it.first<=target){
                    it.second--;
                    path.push_back(it.first);
                    solve(mp,target,currsum+it.first,ans,path,k);
                    path.pop_back();
                    it.second++;
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>path;
        unordered_map<int,int>mp;
        for (int i=1;i<10;i++){mp[i]=1;}
        solve(mp,n,0,ans,path,k);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};