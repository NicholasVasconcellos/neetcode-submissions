class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // O (n * log(k))


        // Keep  a max Heap of Size K (Keeping the max of distance)
        // Keep a set just to returnt he values (unordered)

        priority_queue<pair<double, vector<int>>> maxDistances;
        // use the double comparator, keep the point to reference


        struct pointHash{
            size_t operator()(const vector<int>& arr)const{
                return hash<int>()(arr[0]) ^ (hash<int>()(arr[1]) << 1);
            }
        };

        // May have duplicate points, or duplicate distances
        unordered_multiset<vector<int>, pointHash> solutionSet; // unordered set with the returned values

        
        for(int i = 0; i < points.size(); i++){ // O(N)
            vector<int> point = points[i];


            // Just use distance square since behaviour will be the same
            double distance = (point[0] * point[0]) + (point[1] * point[1]);

            pair<double, vector<int>>  curr(distance, point);

            if(maxDistances.size() < k){
                // Not at K entries yet just insert
                maxDistances.push(curr); // O(log (k))
                solutionSet.insert(point);  // O(1)
            }
            else if( distance < maxDistances.top().first){
                // remove max value from solution set
                solutionSet.erase(solutionSet.find(maxDistances.top().second));
                    // solutionSet.remove(maxDistances.top().second);
                    // must use erase (no remove in multiset)
                    // must use find to get the index of the element to remove just one
                // Remove max value from the heap
                maxDistances.pop();

                // Add new value to heap and set
                maxDistances.push(curr); // O (log(k))
                solutionSet.insert(point);
            }

        }

        // Shortcut with iterator constructor for vector
        vector<vector<int>> solution(solutionSet.begin(), solutionSet.end());

        // Using for each loop
        // vector<vector<int>> solution;
        // for(vector<int> point : solutionSet){
        //     solution.push_back(point);
        // }


        return solution;
        
    }
};
