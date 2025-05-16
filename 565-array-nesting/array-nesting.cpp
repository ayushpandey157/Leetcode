class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        int result = 0;
		//Search for all sets
        for(int i = 0; i < nums.size(); i++)
        {
            int index = i;
            int count = 0;
			//Count the numbers in one set
            while(!visited[index])
            {
                visited[index] = true;
                index = nums[index];
                count++;                
            }
			//Record the longest set
            result = max(result, count);
        }
        return result;
    }
};