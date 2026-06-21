class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0){return false;}
        
        // Create vector of digits
        vector<int> nums;


        // while number is non zero, get lest signif. digit and divide by 10
        while( x > 0){
            nums.push_back(x % 10);

            x /= 10;
        }

        // Two Pointers
        int i = 0;
        int j = nums.size() - 1;

        while(i < j){
            if(nums[i] != nums[j]){return false;}

            i++;
            j--;
        }

        return true;

        
    }
};