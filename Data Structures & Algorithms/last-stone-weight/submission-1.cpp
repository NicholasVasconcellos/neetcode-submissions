class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Keep max 
        // While size > 1
            // get two largest values
            // pop both from array
            // insert the new value (if any)

        // to make efficient we want to get the top 2 heavist stones

        priority_queue<int> maxHeap;

        // Insert stones into priority queue O(N)
        for(int i = 0; i < stones.size(); i++){
            maxHeap.push(stones[i]);
        }

        // O(N)
        while(maxHeap.size() > 1){
            // Get Top O(1)
            int x = maxHeap.top();
            // Reshuffle O(log N)
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();

            if( x < y){
                maxHeap.push(y - x);
            }
            else if(x > y){
                maxHeap.push(x - y);
            }

        }

        // Return last stone weight    
        if(maxHeap.size() > 0){
            return maxHeap.top();
        }
        return 0;

        
    }
};
