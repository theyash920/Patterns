class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()){
            return false;
        }
        int n = matrix.size();
        int m = matrix[0].size();

        int l0 = 0;
        int h = (n*m) - 1;
        while(l0<=h){

            int mid = (l0 + (h-l0)/2);
            if(matrix[mid/m][mid%m] == target){
                return true;
            }
            else if(matrix[mid/m][mid%m] < target){
                l0 = mid+1;
            }else{
                h = mid -1;
            }
        }
        return false;
        
    }
};
