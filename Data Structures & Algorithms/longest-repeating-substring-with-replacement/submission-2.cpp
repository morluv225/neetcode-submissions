class Solution {
public:
    int characterReplacement(string s, int k) {
     unordered_map<char, int> seen; // freq map
     int l = 0;
     int maxFreq = 0;
     int windowSize = 0;
     int lettersToChange = 0;

     for(int r = 0; r < s.length(); r++)
     {
        seen[s[r]]++; // get the char freq
        maxFreq = max(maxFreq, seen[s[r]]); // get the highest char freq
        windowSize = r-l+1; // the window size (aka the distance between the right and left pointers)
        lettersToChange = windowSize-maxFreq; // calculate how many letters in the window need to be changed in order to have one distinct character

        if(lettersToChange > k) // if that number is > than the number of chars we're allowed to change
        {
            seen[s[l]]--; // shrink the window by removing the leftmost character
            l++; // move the left pointer up
        }

        windowSize = r-l+1; // update the windowSize assuming the window has shrank
     }

     return windowSize;
    }
};
