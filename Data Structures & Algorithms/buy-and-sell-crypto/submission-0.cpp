class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Edge case
        if(prices.size() < 2){return 0;}

        // Init Two pointers
        int i = 0;
        int j = 1;

        int maxProfit = 0;
        int currProfit;

        while(i != j && j < prices.size()){
            currProfit = prices[j] - prices[i];

            if(currProfit > maxProfit){
                maxProfit = currProfit;
            }

            // Skip i to j if smaller
            if(prices[j] < prices[i]){
                i = j;

            }

            // Increment j
            j++;

        }

        return maxProfit;
        
    }
};
