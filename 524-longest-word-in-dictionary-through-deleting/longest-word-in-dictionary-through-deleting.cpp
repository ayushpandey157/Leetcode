class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
      
    
    string ans="";

    for(int i=0; i<dictionary.size(); i++){
    int l=0; 
    int r=0;
     while(l<s.size() && r<dictionary[i].size()){
     if(s[l]==dictionary[i][r]){
        l++;
        r++;
     }
     else{
        l++;
     }
    }
    if(r==dictionary[i].size()){
        if(ans.size()<dictionary[i].size()){
          ans=dictionary[i];  
        }
        else if(ans.size()==dictionary[i].size()){
         ans= min(ans,dictionary[i]);
           
        }
        
    }   
    }
    return ans;
    }
};