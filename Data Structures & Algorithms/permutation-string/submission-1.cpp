class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length())
        {
            return false;
        }

        // initialize two character frequency arrays
        // one for s1
        // the other for the window of s2 that is of length s1
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);

        // get all the char freqs based on the length of s1
        for(int i = 0; i < s1.length(); i++)
        {
            s1Count[s1[i]- 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;

        // compare each character from the array and increment the matches
        // Note even if the characters frequency is 0, that will still count as a match if the other array is also 0
        // Thus we check for every character, hence looping 26 times initially
        for(int i = 0; i < 26; i++)
        {
            if(s1Count[i] == s2Count[i])
            {
                matches++;
            }
        }

        int l = 0;
        // Now we slide our window
        // Set r to be the length of s1 thus creating a window of that length.
        // And we need to traverse s2 string until we reach the end
        for(int r = s1.length(); r < s2.length(); r++)
        {
            if(matches == 26)
            {
                return true;
            }

            // Convert the character s2[r] into an index 0–25
            // Increment its frequency because it enters the window
            int index = s2[r] - 'a'; // 
            s2Count[index]++;

            // Determine if we created a match by adding this new character
            // If we did, increment matches
            if(s1Count[index] == s2Count[index])
            {
                matches++;
            } 
            // if we did not, and we added one too many (aka broke a match)
            // Decrement matches, because we no longer have a match
            else if(s1Count[index] + 1 == s2Count[index])
            {
                matches--;
            }
            
            // Repeat for the removal of the left character
            // Convert s2[l] to an index
            // Decrement its frequency because it leaves the window
            index = s2[l] - 'a';
            s2Count[index]--;
            
            // Again, determine if we created a match by removing that character
            // If we did, increment matches
            if(s1Count[index] == s2Count[index])
            {
                matches++;
            }
            // If we did not, and instead we removed one too many (aka broke a match)
            // Decrement matched
            else if(s1Count[index] - 1 == s2Count[index])
            {
                matches--;
            }

            // Move the left pointer up
            l++;
        }

        // return true if a permutation was found, false otherwise
        return matches == 26;
    }
};
