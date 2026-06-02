class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Return an array with the number of days until a warmer day appears
        // relative to each day

        // Aiming for O(N), avoid N2 brute force approach

        vector<int> result(temperatures.size(), 0);

        stack<pair<int,int>> stk; // first = temp, second = index

        // while looping array, keep the cold days on a stack until finding their warmer day
        // Store the cold temp and their index
        // if we find the hotter day we can start backfilling these past cold days
        // using the index to calculate the amount of days that passed


        for(int i = 0; i < temperatures.size(); i++){
            
            while(!stk.empty() && temperatures[i] > stk.top().first){
                // Found the Hotter Day
                // Continuouly pop stack, & log the entry in the results

                int index = stk.top().second;

                result.at(index) = i - index; 

                stk.pop();

            } 
            
            // Put the current day into the stack
            stk.push(make_pair(temperatures[i], i));

        }

        return result;
        
    }
};
