class Solution {
public:
    int diss(vector<int>& p1, vector<int>& p2){
        return ((p1[0]-p2[0])*(p1[0]-p2[0]))+((p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int>st;
        st.insert(diss(p1,p2));
        st.insert(diss(p1,p3));
        st.insert(diss(p1,p4));
        st.insert(diss(p2,p3));
        st.insert(diss(p2,p4));
        st.insert(diss(p3,p4));
        return !st.count(0) && st.size()==2;
    }
};