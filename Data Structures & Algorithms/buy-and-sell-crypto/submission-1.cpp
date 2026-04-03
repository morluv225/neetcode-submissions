class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
       int buy = prices[0];
       int maxProfit = 0;
       int currentProfit = 0;

       for(int i = 1; i < prices.size(); i++)
       {
            if(prices[i] < buy)
            {
                buy = prices[i];
            }
            else
            {
                currentProfit = prices[i] - buy;
                maxProfit = max(currentProfit, maxProfit);
            }
       }

        return maxProfit;
      
    }
};
