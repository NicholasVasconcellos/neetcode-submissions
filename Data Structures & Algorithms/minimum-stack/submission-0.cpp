class MinStack {
    private:
        vector<int> arr;
        vector <int> minArr;
        int size = 0;
public:
    MinStack() {

        
    }
    
    void push(int val) {
        // Add value to main array
        
        arr.push_back(val);

        // If min Stack empty initalize it
        if(size == 0){
            minArr.push_back(val);
        }
        else if(val < minArr.at(size - 1)){
            // Add new value to top of min Stack
            minArr.push_back(val);
        }
        else{
            // Repeat the Current Min to the top of min stack
            minArr.push_back(minArr.at(size - 1));

        }

        // Update Size
        size++;

        
        
    }
    
    void pop() {
        // Delete last entry on both arrays
        arr.pop_back();
        minArr.pop_back();
        // Update Size
        size--;
        
    }
    
    int top() {
        // Return top of the stack (last element of the array)
        return(arr.at(size - 1));

        
    }
    
    int getMin() {
        // Return current min (last element of the minArray)
        return(minArr.at(size - 1));

        
    }
};
