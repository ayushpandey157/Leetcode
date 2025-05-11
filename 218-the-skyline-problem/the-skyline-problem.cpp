class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second > b.second;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> heights;

        // Convert buildings to start and end events
        for (auto& b : buildings) {
            heights.push_back({b[0], b[2]});   // Start of building
            heights.push_back({b[1], -b[2]});  // End of building
        }

        // Sort events
        sort(heights.begin(), heights.end(), cmp);

        map<int, int> heightMap;
        heightMap[0] = 1; // Ground level
        int currentMax = 0;
        vector<vector<int>> result;

        // Process events
        for (auto& h : heights) {
            int x = h.first, height = h.second;

            // Start of building
            if (height >= 0) {
                heightMap[height]++;
                // Height change check
                if (height > currentMax) {
                    currentMax = height;
                    result.push_back({x, height});
                }
            } else {
                // End of building
                height = -height;
                heightMap[height]--;
                if (heightMap[height] == 0) heightMap.erase(height);

                int newMax = heightMap.rbegin()->first;
                // Height Change check
                if (newMax != currentMax) {
                    currentMax = newMax;
                    result.push_back({x, newMax});
                }
            }
        }

        return result;
    }
};