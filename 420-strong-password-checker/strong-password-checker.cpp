class Solution {
public:
    int strongPasswordChecker(string s) {
        // edge case where s size is 0
        if (s.size() == 0)
            return 6;
        // edge case where s size is 1
        if (s.size() == 1)
            return 5;

        int cnt = 0; // no. of changes needed for consecutive characters
        unordered_map<string, int> mpp;
        int i = 0;

        // We mini a hashmap to check the number of 1.) Uppercases' 2.) Lowercases' 3.) Numbers
        while (i < s.size()) {
            if (isupper(s[i])) mpp["uppercase"]++;
            else if (islower(s[i])) mpp["lowercase"]++;
            else if (isdigit(s[i])) mpp["digits"]++;

            // checking if there are 3 consecutives present then we mini 1 move to remove a conse.
            int j = i;
            while (j < s.size() && s[i] == s[j]) j++;
            int len = j - i;
            if (len >= 3) cnt += len / 3;
            i = j;
        }

        int cnt1 = 0; // To check if one of the alphanumeric's is not present in the password
        if (mpp["uppercase"] == 0) cnt1++;
        if (mpp["lowercase"] == 0) cnt1++;
        if (mpp["digits"] == 0) cnt1++;

        // If the password size is less than 6, return the number of characters needed to reach size 6
        if (s.size() < 6) {
            return max(6 - (int)s.size(), cnt1);
        } 
        else if (s.size() > 20) {
            int len = s.size() - 20; 
            vector<int> res(3, 0); // No. of reduce's we need when 3 conse's are present in a series
            i = 0;
            while (i < s.size()) {
                int j = i;
                while (j < s.size() && s[i] == s[j]) j++;
                int len = j - i;
                if (len >= 3) {
                    res[len % 3]++;
                }
                i = j;
            }
            // To ensure that the size of password is <=20
            for (int k = 0; k < 3; k++) {
                if (len <= 0) break;
                int mini = min(res[k], len / (k + 1));
                cnt -= mini;
                len -= mini * (k + 1);
            }

            cnt -= len / 3;
            return (s.size() - 20) + max(cnt, cnt1);
        }
        return max(cnt, cnt1);
    }
};