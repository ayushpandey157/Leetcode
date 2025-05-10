
class Solution{
public int[] rotate(int[]nums,int k){
     List<Integer> arr=new ArrayList<>();
     for(int i:nums){
         arr.add(i);
     }
     Collections.rotate(arr,k);
     
     for(int i=0;i<nums.length;i++){
        nums[i]=arr.get(i);
     }
     return nums; 
}
}