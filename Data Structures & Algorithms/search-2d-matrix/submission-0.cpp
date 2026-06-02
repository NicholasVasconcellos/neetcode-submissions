class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // pretend it was a single array
        // Use arithmethic to find row and col from index

        int numRows = matrix.size(); // Col Size
        int numCols = matrix[0].size(); // 

        int len = numRows * numCols;

        int l = 0;
        int r = len - 1; // Last Entry

        int mid;

        while ( l <= r){
            mid = (l + r) / 2;

            // Convert Mid INdex to Row, Col Index
                // Col Size is the number of rows
                // Row Size is the number of columns

            // Row Index is Index / numRows

            int i = mid / numCols;

            int j = mid % numCols;

            int num = matrix[i][j];

            if(num == target){
                return true;
            }
            else if(num < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return false;


        
    }
};
