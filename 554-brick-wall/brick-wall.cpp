class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        long long  sum=accumulate(wall[0].begin(),wall[0].end(),0LL);
        int n=wall.size();
        // vector<int> vec(sum)
        unordered_map<long long  ,long long> mpp;
        for(int i=0;i<n;i++){
            vector<int > wal=wall[i];
            long long prefix=0;
            for(int j=0;j<wal.size()-1;j++){
                prefix+=wal[j];
                mpp[prefix]++;
            }
        }
        long long maxi=0;
        for(auto it:mpp){
            maxi=max(maxi,it.second);
        }
        // yaha mai rah gaya
        return wall.size()-maxi;
    }
};