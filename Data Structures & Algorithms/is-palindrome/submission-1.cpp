class Solution {
public:
    bool isPalindrome(string s) {
        // initiallize the left and right pointers
        // l staring at the beginning, r starting at the end
        int l = 0, r = s.length() -1;

        // while l < r aka step through until l and r are equal
        while(l < r)
        {
            // if the left character is a space or non alpha numerical
            while(l < r && !alphaNum(s[l]))
            {
                l++; // move the left pointer forward to the next character
            }

            //if the right character is a space or a non alpha numerical
            while(r > l && !alphaNum(s[r]))
            {
                r--; // move the right pointer backward to the next character
            }

            // finally, determine if the lowercase characters are not equal
            if(tolower(s[l]) != tolower(s[r]))
            {
                return false;
            }

            
            // increment and decrement if they are both alphanumerical 
            l++; r--;
        }
        return true;
    }

    // helper function to determine if the character given is alphanumerical
    bool alphaNum(char c)
    {
        return(c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
