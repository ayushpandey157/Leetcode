class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int sign=(nums[i]>0)? 1: -1;
            int k=((i+nums[i])%n+n)%n;
            if((sign==1 &&nums[k]<0 )|| ( sign==-1 && nums[k]>0))
            continue;
            while(k!= i && cnt<n)
            {
                if(sign==1 && (nums[k]<0))
                break;
                else if(sign==-1 &&  (nums[k]>0))
                break;
                int temp= ((k+nums[k])%n+n)%n;
                k=temp;
                cnt++;
            }
            if(k==i && cnt>=1)return true;
        }
        
  return false;
    }
};