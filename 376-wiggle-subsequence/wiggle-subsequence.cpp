class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        if(n == 1) return 1;
        for(int i=0;i<n-1;i++){
            if((nums[i+1]-nums[i] == 0)) continue;
            v.push_back((nums[i+1]-nums[i] > 0)?1:0);
        }
        if (v.empty()) return 1;
        int c = v[0];
        int count = 2;
        for(int i=0;i<v.size();i++){
            if(c != v[i]){
                c = v[i];
                count++;
            }
        }
        return count;
    }
};