class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int low = 0; low < n-2; ++low){
            int cnt = 0;
            int mid = n-2;
            for(int high = n-1; high > low+1; --high,--cnt){
                while(mid > low && nums[low]+nums[mid] > nums[high]){
                    ++cnt;
                    --mid;
                }
                if(cnt>0) ans += cnt;
            }
        }
        return ans;
    }
};