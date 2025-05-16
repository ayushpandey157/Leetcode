#define ll long long
class Solution {
public:
    string substr(string& s, int start,int end){
        string res = "";
        for(int i = start;i<=end;i++)
            res+=s[i];
        return res;
    }
    void swap(string& s, int idx, int r){
        char t = s[idx];
        s[idx] = s[r];
        s[r] = t;
    }
    string constructPartialSortStr(string& s, int start, int idx, int len){
        string temp = substr(s,idx,len); 
        sort(temp.begin(),temp.end());
        string temp1 = substr(s,start,idx-1);
        temp1+=temp;
        return temp1;
    }

    int nextGreaterElement(int n) {
        if(n<=11) // Not possible to have these
            return -1;
        
        string s = to_string(n);
        int len = s.size()-1,idx = -1;

        for(int i=len;i>0;i--){
            if(s[i]>s[i-1]){
                idx = i;
                break;
            }
        }
        

        if(idx == -1) // Cannot be rearranged
            return idx;

        int m = INT_MAX, r = -1;

        // find just greater index to idx - 1
        for(int i = idx; i<=len;i++){
            if(s[i]>s[idx-1]){
                if(s[i] < m){
                    m = s[i];
                    r = i;
                }
            }
        }

        if(m == INT_MAX)
            return -1;
        
        // swap idx-1 & r
        swap(s,idx-1,r);

        // we need to do a ascending sort from index  i to len
        string res = constructPartialSortStr(s,0,idx,len);

        ll num = stol(res);

        if(num>INT_MAX)
            return -1;
        else return num;
    }
};