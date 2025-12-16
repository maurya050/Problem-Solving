class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        int i=0, j=0;

        while(i < n){
            if(matrix[i][j] == target){
                return true;
            }
            if(i+1 < n && matrix[i+1][j] <= target){
                i++;
            }
            else{
                break;
            }
        }
        int first = 0;
        int last = m-1;
        while(first <= last){
            int mid = first + (last-first)/2;
            if(matrix[i][mid] == target){
                return true;
            }
            else if(matrix[i][mid] < target){
                first = mid +1;
            }
            else{
                last = mid -1;
            }
        }
        return false;
    }
};