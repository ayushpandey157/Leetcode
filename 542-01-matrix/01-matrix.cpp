class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();;
        // Initialize the answer matrix with a large value (representing infinity)
        vector<vector<int>> ans(n, vector<int>(m,100001));
        // Queue for BFS traversal; stores coordinates of cells
        queue<pair<int,int>> q;

        // Push all 0-cells into the queue and mark their distance as 0
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        vector<bool> visited(n*m); 

        while(!q.empty()) {
            pair<int,int> u= q.front();
            int i=u.first, j=u.second;
            q.pop();

            if(visited[m*i+j]) continue; // Skip if already visited
            visited[m*i+j] = true;

            // Check and update neighbors
            if(i>0) {
                ans[i-1][j] = min(ans[i-1][j], ans[i][j]+1); // up
                q.push(make_pair(i-1,j));
            }
            if(j>0) {
                ans[i][j-1] = min(ans[i][j-1], ans[i][j]+1); // left
                q.push(make_pair(i,j-1));
            }
            if(i<n-1) {
                ans[i+1][j] = min(ans[i+1][j], ans[i][j]+1); // down
                q.push(make_pair(i+1,j));
            }
            if(j<m-1) {
                ans[i][j+1] = min(ans[i][j+1], ans[i][j]+1); //right
                q.push(make_pair(i,j+1));
            }
        }


        return ans;
        
    }
};