class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size(), s = 0;
        for(int i : machines) s += i;
        if(s % n != 0) return -1;
        s /= n;
        int p = machines[0], t0 = 0, t1 = 0, res = 0;
        for(int i = 1; i < n; ++i) {
            if(p > s) {
                t1 += p - s;
                p += machines[i] - s;
            }else if(p < s) {
                t0 += s - p;
                p += machines[i] - s;
            }else {
                p = machines[i];
            }
            res = max(res, t1);
            t1 = t0;
            t0 = 0;
        }
        return max(res, t1);
    }
};