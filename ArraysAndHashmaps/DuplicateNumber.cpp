class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>count;
        int n = nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        if(count[nums[i]] > 1){
            return true;
        }
        }
        return false;
    }
};