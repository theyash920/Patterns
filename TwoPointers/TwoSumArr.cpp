//After sorting, duplicate pairs will always appear consecutively. 
//So you only need to check against the last inserted pair, not the entire result.
// no need of above text is this ques
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right){
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left + 1, right + 1};  // 1-indexed
            } else if(sum < target){
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};