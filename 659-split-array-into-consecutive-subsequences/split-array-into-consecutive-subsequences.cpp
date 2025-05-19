class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> mp, hp;
        for(auto it: nums)
            mp[it]++;
        for(auto i: nums){
            if(mp[i]==0)   continue;
            if(hp[i]>0){
                hp[i]--;
                hp[i+1]++;
                mp[i]--;
            }
            else if(mp[i]>0 && mp[i+1]>0 && mp[i+2]>0){
                mp[i]--;
                mp[i+1]--;
                mp[i+2]--;
                hp[i+3]++;
            }
            else
                return false;
        }
        return true;
    }
};