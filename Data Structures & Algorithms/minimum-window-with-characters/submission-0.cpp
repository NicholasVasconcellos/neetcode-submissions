class Solution {
public:
    string minWindow(string s, string t) {
        // Target Map
        unordered_map<char,int> targetMap;

        for(char c: t){
            if(targetMap.count(c) == 0){
                targetMap[c] = 1;
            }
            else{
                targetMap[c]++;
            }
        }

        // Current Map: Window
        unordered_map<char,int> window;

        int solutionLen = INT_MAX;
        int solutionStartIndex = 0;

        int l = 0;
        int r = 0;

        char currChar;

        int matchCount = 0;
        int targetMatchCount = t.size();

        while(r < s.size()){
            currChar = s[r];

            // Update Window Map
            if(window.count(currChar) == 0){
                window[currChar] = 1;
            }
            else{
                window[currChar]++;
            }

            // if letter was a hit, and we didn't already have enough
            if(targetMap.count(currChar) > 0 && window[currChar] <= targetMap[currChar]){
                matchCount++;
            }

            // Check if it's a solution and keep contracting if so
            while(matchCount == targetMatchCount){

                // Log Curr Solution if smaller than curr
                int currLen = r - l + 1;
                if(currLen < solutionLen){
                    solutionLen = currLen;
                    solutionStartIndex = l;
                }

                // Contract the Window from the left

                // Update match count if we had just enough of the character
                if(targetMap.count(s[l]) > 0 &&  window[s[l]] == targetMap[s[l]]){
                    // Remove Match
                    matchCount--;
                }

                // Update window Map
                window[s[l]]--;

                // Shrink Window
                l++;
            }

            // Go to next character
            r++;
        }

        if(solutionLen != INT_MAX){
            return s.substr(solutionStartIndex,solutionLen);
        }
        else{
            return "";
        }
        

        
    }
};
