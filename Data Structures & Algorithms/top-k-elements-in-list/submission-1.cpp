class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<vector<int>> freq(nums.size() +1);
        unordered_map<int,int> count;

        for(int num:nums)
        {
            count[num]++; // increment the count of every integer found in nums
        }

        for(const auto& entry:count)
        {
            freq[entry.second].push_back(entry.first); // the index of freq is the amout of times a number appears
        }
        
        vector<int> res; // result vector 

        for(int i = freq.size()-1; i>0; i--)
        {
           for(int n:freq[i])
           {
            res.push_back(n);
           }

           if(res.size() == k)
           {
            return res;
           }
        }

        return res;

    }
};
