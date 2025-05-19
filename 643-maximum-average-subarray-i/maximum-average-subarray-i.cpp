class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double ans=INT_MIN;
        int i=0,j=0;
        double sum=0;
        while(j<n){
            sum+=nums[j];
            if(j+1>=k){
                ans=max(ans,sum/k);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};