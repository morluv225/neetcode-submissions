class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       
       vector<vector<int>> freq(nums.size() + 1);
       unordered_map<int,int> count;

        for(int n:nums)
        {
            count[n]++;
        }

        for(const auto& entry: count)
        {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;

        for(int i = freq.size() -1; i > 0; i--)
        {
            for(int j: freq[i])
            {
                res.push_back(j);
            }

            if(res.size() == k)
            {
                return res;
            }
        }

        return res;

    }
};
