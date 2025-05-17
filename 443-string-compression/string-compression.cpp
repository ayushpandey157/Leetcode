class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int idx=0;
        for(int i=0;i<n;i++){
            int count=0;
            while(i+1<n && chars[i]==chars[i+1]){
                count++;
                i++;
            }

            chars[idx++]=chars[i];
            if(count==0) continue;

            string temp=to_string(count+1);
            for(int x=0;x<temp.length();x++){
                chars[idx++]=temp[x];
            }
        }
        return idx;
    }
};