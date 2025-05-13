class Solution {
public:

    std::string toBase(int n, int base) {
        if (n == 0) return "0";
        std::string result;
        while (n > 0) {
            result = std::to_string(n % base) + result;
            n /= base;
        }
        return result;
    }

    bool isPowerOfN(int n, int base) {
        if (n <= 0) return false;

        std::string baseN = toBase(n, base);
        if (baseN[0] != '1') return false;
        for (int i = 1; i < baseN.length(); ++i) {
            if (baseN[i] != '0') return false;
        }
        return true;
    }

    bool isPowerOfThree(int n) {
        return isPowerOfN(n, 3);
    }
};