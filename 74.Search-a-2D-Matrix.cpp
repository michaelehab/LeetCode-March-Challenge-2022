class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int start = 0, end = rows * cols - 1;
        
        while(start <= end){
            int mid = start + (end - start) / 2;
            int element = matrix[mid / cols][mid % cols];
            if (target == element) return true;
            else if(target < element) end = mid - 1;
            else start = mid + 1;       
        }
        return false;
    }
};