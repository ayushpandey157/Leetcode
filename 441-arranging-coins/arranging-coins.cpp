class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1, right = n;
        while (right >= left) {
            long mid = left + (right - left) / 2;
            if(n == mid * (mid + 1) / 2) return mid;
            if(n > mid * (mid + 1) / 2)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};