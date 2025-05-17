#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
int rs=0;
sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){return a[1]<b[1];});
int end=INT_MIN;
for(auto&interval:intervals){
if(interval[0]<end){
rs++;
}else{
end=interval[1];
}
}
return rs;
}
};