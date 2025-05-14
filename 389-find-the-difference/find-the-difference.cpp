class Solution {
public:
    char findTheDifference(string s, string t) {
        string str = s+t;
        char chxor=0;
        for(char che : str){
            chxor = chxor^che;
        }
        return chxor;
    }
};