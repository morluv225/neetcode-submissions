class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, int> seenS;
        unordered_map<char, int> seenT;

        for(int i = 0; i < s.size(); i++)
        {  
            seenS[s[i]]++;
            seenT[t[i]]++;
        }

        return seenS == seenT;
        
    }
};
