class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set;

        int maxLength = 0;
        int left = 0;

        for(int right = 0; right < s.length(); right++)
        {
           while(set.count(s.at(right)))
           {
                set.erase(s.at(left));
                left++;
           }

           set.insert(s.at(right));
           maxLength = max(maxLength, right-left + 1);
        }

        return maxLength;

    }
};
