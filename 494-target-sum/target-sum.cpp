class Solution {
public:
    int n;
    int t;
    int ans;
    void rec(vector<int>& nums, int sum ,int idx){
        if(idx >= n){
            if(sum == t) {
                ans++;
            }
            return;
        }
        //Add
        rec(nums, sum + nums[idx], idx+1);
        //Subtract
        rec(nums, sum - nums[idx], idx+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans = 0;
        n = nums.size();
        t = target;
        rec(nums, 0, 0);
        return ans;

    }
};