class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair <int , int>>q;
        q.push({0 , 0});
        set <pair <int , int>> st;
        while (!q.empty()) {
            auto node = q.front();
            int curx = node.first;
            int cury = node.second;
            if (curx + cury == target) return true;
            q.pop();
            // transistions;
            // fill one jug complete
            // fill second jug complete
            // empty one/two jugs complete
            // fill one from second
            // fill second from one
            if (st.find({x,cury}) == st.end() && curx < x) {
                q.push({x,cury});
                st.insert({x,cury});
            }
            if (st.find({curx,y}) == st.end() && cury < y) {
                q.push({curx,y});
                st.insert({curx,y});
            }
             if (st.find({0,cury}) == st.end() && curx > 0) {
                q.push({0,cury});
                st.insert({0,cury});
            }
            if (st.find({curx,0}) == st.end() && cury > 0) {
                st.insert({curx,0});
            }
            int mn = min(curx , y - cury);
            // pouring water into jug 2 from jug1
            if (st.find({curx - mn , cury+mn}) == st.end() && cury < y) {
                q.push({curx - mn , cury+mn});
                st.insert({curx - mn , cury+mn});
            }
            // pouring water into jug 1 from jug2
            mn = min(x - curx , cury);
            if (st.find({curx + mn , cury-mn}) == st.end() && curx < x) {
                q.push({curx + mn , cury-mn});
                st.insert({curx - mn , cury+mn});
            }
        }
        return false;
    }
};