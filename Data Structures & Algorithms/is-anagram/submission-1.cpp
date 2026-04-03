class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
        {
            return false;
        }

        // create two unordered maps to track the character frequency of each string
        unordered_map<char, int> sPtr;
        unordered_map<char, int> tPtr;

        for(int i = 0; i < s.size(); i++)
        {
            // increment the number of each character in each string
            sPtr[s[i]]++;
            tPtr[t[i]]++;
        }

        return sPtr == tPtr; // compare if the maps are equal in both keys and values

    }
};
