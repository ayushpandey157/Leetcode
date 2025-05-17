class Solution {
public:
    bool allZero(vector<int>&count){
        return count==vector<int>(26,0);
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.length(),k=p.length();
        vector<int>ans;
        vector<int>count(26,0);
        for(char &ch:p) count[ch-'a']++;
        int i=0,j=0;
        while(j<n){
            count[s[j]-'a']--;
            if(j-i+1==k){
                if(allZero(count)){
                    ans.push_back(i);
                }
                count[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};