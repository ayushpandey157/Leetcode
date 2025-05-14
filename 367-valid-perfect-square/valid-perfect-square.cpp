class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long i = (long)num; i > 0; i--)
        {
            if(i * i == num)
                return true;
        }
        return false;
    }
};