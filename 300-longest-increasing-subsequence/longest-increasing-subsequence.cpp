//app1 form 1 (take or not take) n^2
//tabulation
//space optimx(curr,next)
//2.ending form (ending at level) n^2(n transition)
//endding forn tabulatoion(best)
//6.printing lis(using hash vector and backtrack)
////LIS (NLOGN USING BS)

// class Solution {
//     int dp[2502][2502];//dp[level][prevind]
//     int rec(int level,int prevind,vector<int>&nums){
//         int n=nums.size();
//         if(level==n) return 0;
//         if(dp[level][prevind+1]!=-1) return dp[level][prevind+1];

//         //not take
//         int ans=1;//min ans
//         ans=rec(level+1,prevind,nums);
//         //take'
//         if(prevind==-1 || nums[level]>nums[prevind])
//         ans=max(ans,1+rec(level+1,level,nums));
//         return dp[level][prevind+1]=ans;
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//     memset(dp,-1,sizeof(dp));
//     int n=nums.size();
//     int level=0;
//     int prevind=-1;//cordinata shift is required(dp[prevind+1])
//     return rec(level,-1,nums);   
//     }
// };




////2.ending form (ending at level)  dp[level](n transition)
//a.either length=1(start new lis) or previous (LIS+1)
//tc-(n2) sc-(n2)+0(n)
// class Solution{
//     int dp[2501];//dp[level]

//     int rec(int level,vector<int>& nums){
//         //bc
//        // if(level<0) return 0;
//         if(dp[level]!=-1) return dp[level];
//         int ans=1;
//         for(int prevlevel=0;prevlevel<level;prevlevel++){
//             if(nums[level]>nums[prevlevel])
//             ans=max(ans,rec(prevlevel,nums)+1);//prevlis+1
//         }
//         return dp[level]=ans;
//     }
//     public:
//      int lengthOfLIS(vector<int>& nums) {
//      memset(dp,-1,sizeof(dp));
//      int n=nums.size();
//      int level=n-1;
//      int maxlis=1;
//      //find lis for each ending index and take max of all
//      for(int i=0;i<n;i++){
//         maxlis=max(maxlis,rec(i,nums));
//      }
//      return maxlis;
//     //ending form
// }
// };





//tabulation (to practice)
// class Solution{
//     public:
//      int lengthOfLIS(vector<int>& nums) {
//      int n=nums.size();
//      vector<vector<int>>dp(n+1,vector<int>(n+1,0));//dp[n+1][n+1] //coordinate shift
//      // dp[level][prevlevel]->forloop
//      //1.level n-1->0
//      //2.prevlevel level-1-> -1 ###########################
//      for(int level=n-1;level>=0;level--){
//         for(int prevlevel=level-1;prevlevel>=-1;prevlevel--){
//         //copy the rec
//         int ans=0;
//         //not take
//         ans=dp[level+1][prevlevel+1];
//         //take'
//         if(prevlevel==-1 || nums[level]>nums[prevlevel])
//         ans=max(ans,1+dp[level+1][level+1]);
//         dp[level][prevlevel+1]=ans;
//         }
//      }
//      return dp[0][-1+1];
// }
// };





//space optimization
// class Solution{
//  public:
//   int lengthOfLIS(vector<int>& nums) {
//   int n=nums.size();
//   vector<int>curr(n+1,0),next(n+1,0);

//   for(int level=n-1;level>=0;level--){
//     for(int prevlevel=level-1;prevlevel>=-1;prevlevel--){
//         int ans=next[prevlevel+1];//nt
//         if(prevlevel==-1 ||nums[level]>nums[prevlevel])
//         ans=max(ans,1+next[level+1]);
//         curr[prevlevel+1]=ans;
//     }
//     next=curr;
//   }
//   return next[-1+1];//dp[0][-1] +1 for cordinate shift
// }
// };




//endding forn tabulatoion(best)
//for each index check all prev indexes if any it can be become the ending of any lis or it will start a new lis
// class Solution{
//     public:
//     int lengthOfLIS(vector<int>& nums) {
//     int n=nums.size();
//     int maxi=1;
//     vector<int>dp(n,1);
//     for(int i=0;i<n;i++){
//         for(int prevind=0;prevind<i;prevind++){
//         if(nums[prevind]<nums[i])
//         dp[i]=max(dp[i],1+dp[prevind]);
//         }
//         maxi=max(maxi,dp[i]);
//     }
//     return maxi;
// }
// };







//printing using ending form
// class Solution{
//     public:
//     vector printLIS(vector<int>& nums) {
//     int n=nums.size();
    
//     vector<int>dp(n,1);
//     vector<int>hash(n,0);
//     for(int i=0;i<n;i++) hash[i]=i;
    
//     for(int i=0;i<n;i++){
//         for(int prevind=0;prevind<i;prevind++){
//         if(nums[prevind]<nums[i]){
        
//         hash[i]=prevind;
//         }
//        // maxi=max(maxi,dp[i]);
//     }
//     //now get the index with highest dp[i]
//     int maxi=0;
//     for(int i=0;i<n;i++) 
//     if(dp[i]>maxi) maxi=i;
//     //now track ind i at 
//     vector<int>lis;

    
// }
// };





//LIS (NLOGN USING BS)
class Solution{
    public:
     int lengthOfLIS(vector<int>& nums) {
        vector<int>lis;
        for(auto num:nums){
            //find correct pos of num in lis 
            auto it=lower_bound(lis.begin(),lis.end(),num);
            if(it!=lis.end())
            *it=num;
            else 
            lis.push_back(num);// if it is greater than all elements put at last
        }
        return lis.size();
}
};



