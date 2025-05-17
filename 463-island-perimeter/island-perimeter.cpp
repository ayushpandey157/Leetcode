class Solution {
    int n;
    int m;
    int bfs(int i , int j , vector<vector<int>>& grid,vector<vector<int>> &vis) {
        int ans =0;
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            int delr[] = {-1,0,1,0};
            int delc[] = {0,1,0,-1};
            int ct = 0;
            int av = 0;
            for(int k =0;k<4;k++) {
                int nr = row + delr[k];
                int nc = col + delc[k];
                if(nr >=0 && nr < n && nc >=0 && nc < m){
                    if(grid[nr][nc]==1 && vis[nr][nc]==0) {
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                        ct++;
                    }
                    else if(grid[nr][nc] == 1 && vis[nr][nc]==1) {
                        av++;
                    }
                }
            }
            ans += (4-ct-av);
        }
        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int i =0;
        int j =0;
        for(i=0;i<n;i++) {
            bool found = false;
            for(j=0;j<m;j++) {
                if(grid[i][j]==1){
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        } 
        vector<vector<int>> vis(n,vector<int>(m,0));
        return bfs(i,j,grid,vis);
    }
};