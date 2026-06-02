class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        if(position.size() == 0){return 0;}

        // Given position and speed of eac car
        // When  car catches up to another they proceed at same speed
        // if they are caught up they are on the same fleet
        // Return the total number of fleets


        // map each position to it's time to reach, and keep the positions sorted

        // so we can use an ordered_map

        map<int, float> posToTime;

        // populate the map O(N Log N)
        for(int i =0; i<position.size(); i++){
            float time = (target - position[i]) / (float)speed[i];

            posToTime[position[i]] = time;
        }

        // Loop the map in order to check the number of fleets
        // Start from the Largest Position

        // track the current fleet, starts as the one at the last position
        pair<int,float> currFleet =  make_pair(posToTime.rbegin()->first, posToTime.rbegin()->second);
        int count = 1;
        // Counts the number of fleets

        

        for(auto it = posToTime.rbegin(); it != posToTime.rend(); ++it){ // O(N) only check the fleet in front of it
            // Skip the first entry
            if(it == posToTime.rbegin()){continue;}
            

            int currPos = it->first;
            float currTime = it->second;

            // Always check the fleet in front to see if you will join it or create a new one
            // if this car would arrive before the fleet in front of it, add it to curr fleet, otherwise create new fleet
            if(currTime > currFleet.second){
                // add new fleet
                currFleet = make_pair(currPos, currTime);
                // update count
                count++;
            }




        }

        return count;
        
    }
};
