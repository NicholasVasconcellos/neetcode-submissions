class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Formulat

        // K will be mroe than 0 since zero would take infinite time

        // k will be less than tot bananas / h

        // Binary search for a k between the two
            // if the K is not sufficient check to the right
                // l = mid + 1
            // if the K is sufficient check to the left

                // Store the K
                // r = mid - 1
        int min = 1; // Lower Bound (k will be greater than zero)


        // Upper Bound is the largest, pile, since if he eats that in 1 hours then that's as fast as it can go
        int max = 0;
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > max){max = piles[i];}
        }

        int k;
        int bestK = INT_MAX;

        while(min <= max){
            // Set k as the midpoint of the valid range
            // Prevent overflow
            // k = (min + max) / 2;
            // (a + b) / 2 = a/2 + b/2 = 2a/2 -a/2 + b/2 = a + (- a + b) / 2
            k = min + (max - min)/2; 

        
            // Check if it's a solution
            long long time = 0;
            for(int i =0; i < piles.size(); i++){
                // Add the Number of hours to eat the pile
                time +=  piles[i] / k; // Rounds Down

                if(piles[i] % k != 0){
                    // If remainder add one to round up
                    time++;
                }
            }

            if(time <= h){
                // Solution is Valid
                // Log Solution, if better
                if(k < bestK){bestK = k;}

                // Check Smaller Values only
                max = k - 1;
            }
            else{
                // Invalid solution
                // Check larger Values Only
                min = k + 1;
            }
        }

        return bestK;
    }
};
