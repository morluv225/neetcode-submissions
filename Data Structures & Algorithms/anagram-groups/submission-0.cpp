class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    
        unordered_map<string,vector<string>> res; // hash map to hold the string key and the array of string value
        for(const auto&s:strs) // for every string in strs
        {
             vector<int> count(26, 0); // initialzie a count array to count all 26 letters.
             for(char c:s) // for ever character c in each string s
             {
                // count the frequency of letters in the string and map that amount to corresponding letter
                // c - 'a' calculates the zero-based index of the letter. i.e 'a' - 'a' = 0, 'b' - 'a' = 1....'z'- 'a' = 25 
                count[c-'a']++; 
             }

             // convert the integer frequency value to a string and store it in key 
             string key = to_string(count[0]);  

             // loop through every value in the count array starting at index 1 because we already captured the value at index 0 above
             for(int i =1; i < 26; ++i) 
             {
                // append the frequency of every other character to key. i.e. ", <value>" is being appended. ex. ",2", ",0", etc.
                // so the key string may now look like "1,2,0"
                key += ',' + to_string(count[i]); 
             }

             // let our frequency string be the key for our hashmap and let the word we're iterating through be the value
             // all anagrams have the same letter frequency aka they share the same key.
             // the res will look something like this:
             /*
             res = {
                "1,0,0,0,1,0.....,1" => ["eat", "tea", "ate"],
                "1,0,0,0,0,0,.....1" => ["bat"],
                "1,0,0,0,1,0,.....1" => ["tan", "nat"]
             }
             */
             res[key].push_back(s); 
        }

        vector<vector<string>> result; // create another array of arrays
        for(const auto&pair:res) // for every key value pair in res 
        {   
            // append the value from the key value pairs (i.e the list of anagrams) to thje final list. 
            result.push_back(pair.second);
        }

        return result;
    }
};
