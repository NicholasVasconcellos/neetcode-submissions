class TimeMap {
    // Map of std::string to Array of std::string, int

    struct data{
        std::string value;
        int timestamp;

        data(std::string value, int timestamp){
            this->value = value;
            this->timestamp = timestamp;
        }
    };

    std::unordered_map<std::string,std::vector<data>> timeMap;


public:
    TimeMap() {
        // Constructor
        
    }
    
    void set(std::string key, std::string value, int timestamp) {
        if(timeMap.count(key) == 0){
            // New key
            timeMap[key] = std::vector<data>{data(value, timestamp)};

        }
        else{
            timeMap[key].push_back(data(value, timestamp));
        }

        // Values are strictly increasing so no duplicate timestamp check needed
        
    }
    
    std::string get(std::string key, int timestamp) {
        if(timeMap.find(key) == timeMap.end()){
            // Key not found
            return "";
        }

        // Binary search for the timestamp in the array (sorted)
        return binSearch(key, timestamp, timeMap[key]);

        
    }

    std::string binSearch(std::string key, int target, std::vector<data>& arr){
        // Bin search to get the value or the largest value that is < target

        std::string result = "";

        int l = 0;
        int r = arr.size() - 1;

        while(l <= r){
            int mid =  l + (r-l)/2;

            if(target == arr[mid].timestamp){
                result = arr[mid].value;
                return result;
            }
            if(target > arr[mid].timestamp){
                // possible solution, store it
                result = arr[mid].value;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return result;
    }
};
