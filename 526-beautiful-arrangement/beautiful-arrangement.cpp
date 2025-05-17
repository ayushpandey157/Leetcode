class Solution {
public:
/*
Note: 
Instead of placing elements from left to right (i.e., index 1 to n), we 
place them from right to left (i.e., from n down to 1). This approach 
reduces the number of recursive calls because the divisibility conditions 
(val % pos == 0 || pos % val == 0) are harder to satisfy when the position 
is large. For example, at position 4, only numbers like 1, 2, and 4 can be 
placed, which naturally prunes many branches early.

Example:

At position 3, valid choices might be {1, 3} (since 3 % 1 == 0, and 3 % 3 
== 0).

But at position 1, all numbers satisfy the condition (val % 1 == 0), so it 
creates more branching.

Starting from higher positions optimizes the recursion by limiting the 
number of valid choices early.

*/
    int ans = 0;

    void recursion(int level, set<int>& choices){
        //Base Case
        if(level == 0){
            ans++;
            return;
        }
        //Recursive Code
        set<int> temp = choices;
        for(auto it : temp){
            if(it%level == 0 || level%it == 0){
                choices.erase(it);
                recursion(level-1,choices);
                choices.insert(it);
            }
        }
        return;
    }

    int countArrangement(int n) {
        ans = 0;
        set<int> choices; 
        for(int i = 1 ; i <= n ; i++){
            choices.insert(i);
        }  
        recursion(n,choices);
        return ans;
    }
};