class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Implementign Binary Search

        // Start at mid point
            // if target smaller update r to mid
            // else if target bigger update l to mid
            // else found and return
        // return -1 (not found)

        int l = 0;
        int r = nums.size() - 1;

        int mid;

        while(l <= r){
            // Compute Mid
            mid = (l + r) / 2 ;

            if( nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

       return -1;
    }
};
