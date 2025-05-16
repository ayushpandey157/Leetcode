class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int,bool> candyExist;
        int candy = candyType.size() / 2;
        int cnt = 0;
        for (int i : candyType) {
            if (!candyExist[i]) { // \U0001f36c Found a new type of candy
                cnt++;
                candyExist[i] = true;
            }
        }
        return min(cnt, candy); // ✅ Choose the max unique candies possible
    }
};