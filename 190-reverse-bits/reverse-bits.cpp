class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        vector<int>v;
        int j=0;
        for(int i=1;i<=32;i++){
            v.push_back(n%2);
            n/=2;
        }
        reverse(v.begin(),v.end());
        for(auto u:v){
            ans+=1LL*pow(2,j)*u;
            j++;
        }
        return ans;
    }
};