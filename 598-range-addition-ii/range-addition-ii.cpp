class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // Initialize the maximum dimensions based on the original matrix size
        int col = n, row = m;
        int k = ops.size(); // Number of operations
        
        // Iterate through each operation
        for (int i = 0; i < k; i++) {
            int l = ops[i][0]; // Row limit from operation
            int r = ops[i][1]; // Column limit from operation
            
            // Update the minimum dimensions based on operations
            col = min(col, r); // Update column limit
            row = min(row, l); // Update row limit
        }
        
        // Return the count of integers with the maximum value
        return col * row; // Area of the rectangle defined by the min dimensions
    }
};