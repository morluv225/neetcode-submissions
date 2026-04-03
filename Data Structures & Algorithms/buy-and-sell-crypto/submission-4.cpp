class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0; // assign left to start at the farthest left index
        int r = 1; // assign right to start one pos over from left
        int maxProf = 0;

        while (r < prices.size()) // until the right pointer reaches the end of the array
        {
            if(prices[l] < prices[r]) // if the left price is less than the right price
            {
                int profit = prices[r] - prices[l]; // get the current profit
                maxProf = max(profit, maxProf); // get the max profit
            }
            else // if the left price is greater or equal to the right price, assign the left pointer the right pointers index
            {
                l = r;
            }

            r++; // movve the right pointer up
        }

        return maxProf;
    }    
};
