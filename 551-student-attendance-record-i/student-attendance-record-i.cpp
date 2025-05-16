class Solution {
public:
    bool checkRecord(string s) {
       int l=0,a=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A'){
                a++;
                l=0;
            }
            else if(s[i]=='L'){
                l++;
                
            }
            else{
                l=0;
            }
            if(l>=3||a>=2){
                return false;
            }
        }
        return true;
    }
};