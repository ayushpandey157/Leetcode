/*
standard euiler tour problem: bring a path by visiting all the edges exactly once.

- if all the nodes have even degree then u will end up with a euiler circuit (ending in a same node on which u have started)
- for a path, exactly two nodes should have odd degree and you can start with any of them, the resultant path length would be (no of edges + 1) ofc.
*/

class Solution {
public:

    void dfs(string curr,unordered_map<string,vector<string>> &g,vector<string> &ans) {

        while(!g[curr].empty()) {

            string v = g[curr].back();
            g[curr].pop_back();
            dfs(v,g,ans);
        }

        ans.push_back(curr);

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,vector<string>> g;

        for(auto &it : tickets) {
            g[it[0]].push_back(it[1]);
        }

        for(auto &it : g) {
            vector<string> tmp = it.second;
            sort(tmp.rbegin(),tmp.rend());
            it.second = tmp;
        }
        vector<string> ans; 
        dfs("JFK",g,ans);
        
        reverse(ans.begin(),ans.end());

        return ans;
    }
};