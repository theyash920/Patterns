class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int leftwater =0;
        int rightwater = 0;
        int water = 0;
        while(left < right){
            if(height[left] <= height[right]){
                leftwater = max(leftwater, height[left]);
                water = water + leftwater - height[left];
                left++;
            }else{
                rightwater = max(rightwater,height[right]);
                water = water + rightwater - height[right];
                right--;
            }
        }
        return water;

        
    }
};
