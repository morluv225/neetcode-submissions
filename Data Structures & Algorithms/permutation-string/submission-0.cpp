class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // if the first string is longer than the second string
        // then its not possible that there are permutations 
        if(s1.length() > s2.length()) return false;

        // create two frequency arrays to count the char freqs of each string
        vector<int> s1Count(26,0);
        vector<int> s2Count(26,0);

        for(int i = 0; i < s1.length(); i++)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;

        for(int i = 0; i < 26; i++)
        {
            if(s1Count[i] == s2Count[i])
            {
                matches++;
            }
        }
        
        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++)
        {
            if(matches == 26) return true;

            int index = s2[r] -'a';
            s2Count[index]++;

            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] + 1 == s2Count[index]) {
                matches--;
            }

            index = s2[l] - 'a';
            s2Count[index]--;
            if (s1Count[index] == s2Count[index]) {
                matches++;
            } else if (s1Count[index] - 1 == s2Count[index]) {
                matches--;
            }
            l++;

        }

        return matches == 26;
    }
};
