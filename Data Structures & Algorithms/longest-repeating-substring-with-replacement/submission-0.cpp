class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char, int> seen; // hash map to count the frequency of the characters
        int left = 0;
        int windowSize = 0;
        int maxFreq = 0;
        int maxWindow = 0;

        for(int right = 0; right < s.length(); right++)
        {
            seen[s.at(right) - 'A']++; //update the frequency of the current character
            maxFreq = max(maxFreq, seen[s.at(right)-'A']); //update the max frequency

            windowSize = right-left +1;

            if(windowSize - maxFreq > k)
            {
                seen[s.at(left) - 'A']--;
                left++;
            }

            windowSize = right-left +1;
            maxWindow = max(maxWindow, windowSize);

        }

        return windowSize;
    }
};
