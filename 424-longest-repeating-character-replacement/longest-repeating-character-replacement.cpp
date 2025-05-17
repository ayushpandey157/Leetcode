class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxCount = 0, result = 0;

        for (int right = 0; right < s.length(); ++right) {
            count[s[right] - 'A']++;
            maxCount = std::max(maxCount, count[s[right] - 'A']);

            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }
            result = std::max(result, right - left + 1);
        }

        return result;
    }
};