class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        //brute force approach
        //time complexity: O(n^2)
        //space complexity: O(1)

        int i,j;
        int ans=0;

        //if size of given array is less than 3, return 0
        if(nums.size()<3)
            return 0;

        //1st loop to iterate over each element as 'starting point'
        for(i=0;i<nums.size()-2;i++)
        {
            //calculate 'initial difference'
            int diff=nums[i+1]-nums[i];
            //2nd loop to check if 'current-difference' matches the 'initial-difference'
            for(j=i+2;j<nums.size();j++)
            {
                //if condition is true, increase the count of 'ans' by 1
                if((nums[j]-nums[j-1])==diff)
                    ans++;
                //otherwise, break the inner loop
                else
                    break;
            }
        }    
        //return the total count of 'ans'(arithematic slices)
        return ans;
    }
};