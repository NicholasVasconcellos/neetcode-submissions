class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Find min (Start Index)
        int l = 0;
        int r = nums.size() - 1;

        while (l < r){
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]){
                // min is to the right of mid
                l = mid + 1;
            }
            else{
                // min is either mid or to the left
                r = mid;
            }
        }
        // Ends when r = l, this will be the min

        // Adjust r to be the last index in the virtual array

        r = l + nums.size() - 1;

        // Normal bin search using %
        while(l <= r){
            int mid = l + (r-l)/2;

            int adjustedMid = mid % nums.size();

            if(nums[adjustedMid] == target){
                return adjustedMid;
            }
            else if(nums[adjustedMid] < target){
                l = mid + 1;
            }
            else{
                // nums[mid] > target
                r = mid - 1;
            }
        }

        return -1;
        
    }
};
