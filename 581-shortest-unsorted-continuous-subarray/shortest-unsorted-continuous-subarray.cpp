class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int first=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                first=i;
                break;
            }
        }
        int second=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                second=i;
                break;
            }
        }
        int mn=INT_MAX;
        int mx= INT_MIN;
        for(int i=first;i<=second;i++){
            mn=min(mn,nums[i]);
            mx=max(mx,nums[i]);
        }
        for(int i=0;i<first;i++){
            if(nums[i]>mn){
            first=i;
            break;
            }
        
        }
        for(int i=n-1;i>second;i--){
            if(nums[i]<mx){
                second=i;
                break;
            }
        }
        if(first==second&&first==0)
        return 0;
        return second-first+1;
    }
};