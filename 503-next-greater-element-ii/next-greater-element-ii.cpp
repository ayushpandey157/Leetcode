class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Initialize result with -1
        stack<int> st; // Stack to store next greater candidates

        for (int i = 2 * n - 1; i >= 0; --i) {
            int curr = nums[i % n]; // Wrap around for circular array

            // Pop elements smaller or equal to current
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // Only fill result in first pass
            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }

            // Push current for future comparisons
            st.push(curr);
        }

        return ans;
    }
};