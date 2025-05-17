class Solution {
public:
    bool solve(vector<int>& matchsticks,vector<int>&sides, int index){
        if(index == matchsticks.size()){
            if(sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0){
                return true;
            }
        }

        bool ans = false;
        for(int j=0;j<4;j++){
            if(matchsticks[index] <= sides[j]){
                sides[j] -= matchsticks[index];
                ans = ans || solve(matchsticks,sides,index+1);
                if(ans) return true;
                sides[j] += matchsticks[index];
            }
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() <4) return false;
        auto sum = accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4 !=0) return false;
        int sideSum = sum/4;
        vector<int>sides(4,sideSum);
        sort(matchsticks.rbegin(),matchsticks.rend());
        return solve(matchsticks,sides,0);
    }
};