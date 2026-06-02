class Solution {
public:
    int findMin(vector<int> &nums) {

        int min = nums[0];

        int low = 0;
        int high = nums.size() - 1;

        while ( low < high){
            int mid = low + (high - low) /2;

            if(nums[mid] > nums[high]){
                // [mid] is not the min, since it's bigger than [high]
                // the min is to the right of the mid, because that's where the flip is
                low = mid + 1;
            }
            else{
                // nums[mid] < nums[high]
                // [mid] could be the min, and the min is to the left of mid
                high = mid;
            }   
        }

        return nums[low];
        
    }
};
