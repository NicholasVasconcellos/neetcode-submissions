class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {


        priority_queue<int> minHeap;
        // Push numbers as negative to get min heap functionality


        for(int i = 0 ; i < nums.size(); i++){
            // Flip the sign of the number
            int curr = -nums[i];
            if(minHeap.size() < k){
                minHeap.push(curr);
            }

            // Add only absolute values greater than the min
            // Flip the comparator, negative value smaller 
            else if(curr < minHeap.top()){
                minHeap.pop(); // Remove min
                minHeap.push(curr); 
            }
        }

        return minHeap.top() * -1;

    }
};
