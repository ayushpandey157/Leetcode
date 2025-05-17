class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        map<int,int>cnt;
        vector<int>v;
        for(auto u:nums){
            cnt[u]++;
            
        }
        for(auto u:cnt){
            v.push_back(u.first);
        }
        if(v.size()<3) return mx;
        int k=3;
        
        for(int i=v.size()-1;i>=0;i--){
            k--;
            if(k==0){
                return v[i];
            }
        }
        return mx;
    }
};