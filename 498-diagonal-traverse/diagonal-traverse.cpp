class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      vector<int>ans;
      map<int,vector<int>>mp;

      int n=mat.size();
      int m=mat[0].size();

      for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            mp[i+j].push_back(mat[i][j]);
         }
      }
      for(auto [lev,vec]:mp){
         if(lev%2==0) reverse(vec.begin(),vec.end());

          for(int i=0; i<vec.size(); i++){
              ans.push_back(vec[i]);
          }
       }

      return ans;

    }
};