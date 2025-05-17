class Solution {
public:
    string originalDigits(string s) {
        
        int nums[10];
        vector<int> freq(26);// capture frequencies of the alphabet
        for(int i =0 ;i< s.size();i++){
            freq[s[i]-'a']+=1;
        }
        nums[0] = freq['z' - 'a']; // 'z' is unique to zero
        nums[2] = freq['w' - 'a']; // 'w' is unique to two
        nums[4] = freq['u' - 'a']; // 'u' is unique to four
        nums[5] = freq['f' - 'a'] - nums[4]; // 'f' is unique to five, but also includes four
        nums[6] = freq['x' - 'a']; // 'x' is unique to six
        nums[8] = freq['g' - 'a']; // 'g' is unique to eight
        nums[1] = freq['o' - 'a'] - nums[0] - nums[2] - nums[4]; // 'o' is unique to one
        nums[3] = freq['h' - 'a'] - nums[8]; // 'h' is unique to three
        nums[7] = freq['s' - 'a'] - nums[6]; // 's' is unique to seven
        nums[9] = freq['i' - 'a'] - nums[6] - nums[8] - nums[5]; // 'i' is unique to nine
        // string builder to add the integers that 
        // can be formed with non zero frequency to the ans
        string result = "";
        for (int i = 0; i < 10; i++) {
            if (nums[i] != 0) {
                result += string(nums[i], '0' + i);
            }
        }
        return result;
    }
// DONE! 
// BEATS 96%
// Time Complexity: O(n)
// Space Complexity: O(1)
};