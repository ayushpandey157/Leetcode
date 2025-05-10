class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(),v.end(),[]( string &a, string &b){
            int i=0;
            int j=0;
            int na=a.length();
            int nb=b.length();
            int count=0;
            while(a[i%na]==b[j%nb]){
                count++;
                i++;
                j++;
                if(count==na+nb)break;
            }
            return a[i%a.length()]>b[j%b.length()];
            
        });
        if(v[0]=="0")return "0";
        string res="";
        for(int i=0;i<v.size();i++){
            res+=v[i];
        }


        return res;
    }
};