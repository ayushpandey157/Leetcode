class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        unordered_map<int,vector<int>>mp;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[i].size();j++){
                if (grid[i][j]=='1'){
                    mp[i*1000+j];
                    if (i+1<grid.size() && grid[i+1][j]=='1'){
                        mp[i*1000+j].push_back((i+1)*1000+j);
                        mp[(i+1)*1000+j].push_back(i*1000+j);
                    }
                    if (j+1<grid[i].size() && grid[i][j+1]=='1'){
                        mp[i*1000+j].push_back(i*1000+(j+1));
                        mp[i*1000+(j+1)].push_back(i*1000+j);
                    }
                    if (j-1>=0 && grid[i][j-1]=='1'){
                        mp[i*1000+j].push_back(i*1000+(j-1));
                        mp[i*1000+(j-1)].push_back(i*1000+j);
                    }
                    if (i-1>=0 && grid[i-1][j]=='1'){
                        mp[i*1000+j].push_back((i-1)*1000+j);
                        mp[(i-1)*1000+j].push_back(i*1000+j);
                    }
                }
            }
        }
        int a=0;
        unordered_map<int,bool>vis;
        queue<int>q;
        for (auto &it:mp){vis[it.first]=false;}
        for (auto &it:mp){
            if (!vis[it.first]){
                vis[it.first]=true;
                q.push(it.first);
                while (!q.empty()){
                    int front=q.front();
                    q.pop();
                    vector<int>b=mp[front];
                    for (int i=0;i<b.size();i++){
                        if (!vis[b[i]]){
                            q.push(b[i]);
                            vis[b[i]]=true;
                        }
                    }
                }
                a++;
            }
        }
        return a;
    }
};