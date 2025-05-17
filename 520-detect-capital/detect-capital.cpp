class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(isupper(word[i])){
                cnt++;
            }
        }
        if(cnt==1){
            return (isupper(word[0])?true:false);
        }
        return (cnt==n || cnt==0);
    }
};