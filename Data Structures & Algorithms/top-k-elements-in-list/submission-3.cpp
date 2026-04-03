class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // vector of vectors to contain the frequency of each integer
        vector<vector<int>> freq(nums.size()+1);
        // map that will store the integer frequency and the integer
        unordered_map<int, int> count;
        // final result vector
        vector<int> res;

        // get the character frequency
        for(int n: nums)
        {
            count[n]++;
        }
        
        // for every integer and frequency pair, add them to the vector as index and value
        for(const auto& entry:count)
        {
            // index = the frequency, value(s) = whatever integers have that frequency
            freq[entry.second].push_back(entry.first);
        }

        // start at the end of the freq vector and count backwards from most frequent to least
        for(int i = freq.size()-1; i>0; i--)
        {
            for(int n: freq[i])
            {
                res.push_back(n); // push back the most frequent vectors...
            }

            if(res.size() == k) // ...until the res size reaches k
            {
                return res;
            }
        }
    
            return res;
    }
};
