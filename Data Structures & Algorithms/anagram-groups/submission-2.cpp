class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // map to store the character frequency string and the vectork of words that go with it
        unordered_map<string, vector<string>> res;

        for(const auto &s:strs)
        {
            // initialize a count array with 26 indices to 0 to store the char freq
            vector<int> count(26,0);

            //step through every charatcer in the string and update it's freq
            for(char c: s)
            {
                count[c-'a']++; 
            }

            // create the key string by assigning it the first char freq converted to a string
            string key = to_string(count[0]);

            // then concatenate the rest of the character freq to the key with commas in between
            for(int i = 0; i < 26; i++)
            {
                key += "," + to_string(count[i]);
            }

            // add the character freq string key and it's string to the map

            res[key].push_back(s);
        }

        vector<vector<string>> finalResult;

        // step through each key value pair in the map
        // and push back just the array of strings to the final array
        for(const auto& pair:res)
        {
            finalResult.push_back(pair.second);
        }

        return finalResult;
    }
};
