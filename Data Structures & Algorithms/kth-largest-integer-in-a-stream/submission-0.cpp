class KthLargest {
    std::priority_queue<int, vector<int>, greater<int>> heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        // Create  min heap of size K (min will always be at top), get min in O(1)
        for(int i = 0; i < nums.size(); i++){
            add(nums[i]);
        }
        
    }
    
    int add(int val) {
        // Not yet up to 3
        if(heap.size() < k){
            heap.push(val);
        }
        else if(val > heap.top()){
            heap.pop();
            heap.push(val);
        }

        return heap.top();
        
    }
};
