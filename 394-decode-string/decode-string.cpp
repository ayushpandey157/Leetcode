class Solution {
public:
    int i = 0; // Global index for recursion
    string decodeString(string s) {
        string result = "";
        int num = 0;
        while (i < s.length()) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
            } else if (c == '[') {
                i++;
                string nested = decodeString(s); // Recurse for inner string
                string temp = "";
                for (int j = 0; j < num; j++) {
                    temp += nested;
                }
                result += temp;
                num = 0;
            } else if (c == ']') {
                i++;
                return result;
            } else {
                result += c;
                i++;
            }
        }
        return result;
    }
};