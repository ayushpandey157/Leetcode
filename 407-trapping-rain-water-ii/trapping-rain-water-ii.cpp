#define tiii tuple < int , int , int > 
class Solution {
public:

    bool safe(int i, int j, int m, int n){

        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int trapRainWater(vector<vector<int>> &arr) {

        int n = arr.size(), m = arr[0].size(), water = 0;
        int delta[] = {-1, 0, 1, 0, -1};

        priority_queue < tiii, vector < tiii >, greater < tiii > > pq;
        vector < vector < int > > visited(n, vector < int > (m, 0));

        for(int i = 0; i < n; i++){ // vertical Boundaries

            pq.push({arr[i][0], i, 0}) , pq.push({arr[i][m - 1], i, m - 1});
            visited[i][0] = visited[i][m - 1] = 1;
        }

        for(int j = 1; j < m - 1; j++){ // horizontal Boundaries

            pq.push({arr[0][j], 0, j}) , pq.push({arr[n - 1][j], n - 1, j});
            visited[0][j] = visited[n - 1][j] = 1;
        }

        while(!pq.empty()){

            auto [height, x, y] = pq.top();
            pq.pop();

            for(int del = 0; del < 4; del++){

                int newx = x + delta[del], newy = y + delta[del + 1];

                if(safe(newx, newy, m, n) && !visited[newx][newy]){
                    
                    visited[newx][newy] = 1;

                    water += max(height - arr[newx][newy], 0); // Adding the difference into water directly, as we are sure that there is no chance that we will get more water for this cell, as even if we try to put more water, it will leak from the cell we are woking on.
                    pq.push({max(arr[newx][newy], height), newx, newy});
                }
            }
        }

        return water;
    }
};