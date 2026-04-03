class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> seen; // hash map to contain the frequency of the characters
        int left = 0;
        int windowSize = 0;
        int maxFreq = 0;
        int maxWindow = 0;

        for(int right = 0; right < s.length(); right++)
        {
            seen[s.at(right) - 'A']++; // update the frequency of each character in the hash map
            maxFreq = max(maxFreq, seen[s.at(right)-'A']); // update the max freq

            windowSize = right-left +1; // set the current window size

            if(windowSize - maxFreq > k) // if the window size - the maxFreq is > than our target
            {
                seen[s.at(left) - 'A']--; // subtract the character frequency
                left++; // remove a character from the window
            }

            windowSize = right-left +1; // reset the windowSize now that characters have been removed
            maxWindow = max(maxWindow, windowSize); // get the maxWindow size

        }

        return windowSize;
    }
};
