class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3){return 0;}

        // Intialize left pointer at beggining
        int l = 0;
        int l_next = 1;

        // Right Pointer at the end
        int r = height.size() - 1;
        int r_next = r - 1;

        // Get to the first peak on each side
        while(l_next < (height.size() - 1) && height.at(l) < height.at(l_next)){
            l++;
            l_next++;
        }
        // in case we went all the way to the other side
        if(l == r){return 0;}

        while((r_next >= 0) && height.at(r) < height.at(r_next)){
            r--;
            r_next--;
        }

        int sum = 0;

        while(l != r){
            // Get the smallest wall and move from there
            if(height.at(l) < height.at(r)){
                // Move the left until finding someone bigger
                while(l_next < r && height.at(l) > height.at(l_next)){
                    sum += (height.at(l) - height.at(l_next));
                    l_next++;
                }
                // Found someone bigger, update l
                l = l_next;
                // Update next
                l_next = l + 1;
            }
            else{
                // Move the right until finding someone bigger
                while(r_next > l && height.at(r) > height.at(r_next)){
                    sum += (height.at(r) - height.at(r_next));
                    r_next--;
                }
                // Found someone bigger, update R
                r = r_next;
                // Update next
                r_next = r - 1;
            }
        }
        return sum;

    }
};
