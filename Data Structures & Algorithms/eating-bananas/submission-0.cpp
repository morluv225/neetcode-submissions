class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // set the left pointer at 1 to form a continuous array of values 1 -> the largest value in the arr
        int l = 1;
        // set the right pointer to the largest element in the array
        int r = *max_element(piles.begin(), piles.end());
        // set the result value also to the max value because we know that thats
        // the greatets amount of hours it would take to eat all the bananas
        int res = r;

        // standard binary search loop
        while(l <= r)
        {
            int k = (l+r)/2; // get the mid point
            long long totalTime = 0; // create the total time variable that will contain hours it will take to eat all the piles

            // for every amount of bananas in each pile
            // we want to divide the number of bananas by k, and round up to 
            // get the approximate hours it will take to finish each pile
            for(int p: piles)
            {
                totalTime += ceil(static_cast<double>(p)/k);
            }

            // if the total time is less than or equal to the hours we are given to finish each pile
            // this means we've found a value that allows us to finish all the piles in time
            if(totalTime <= h)
            {
                res = k; // set the result to k
                r = k - 1; // remove the right side of the array by moving r before the prev midpoint
            }
            else // if the time is greater than we need to remove the left side of the array and calculate again
            {
                l = k+1;
            }
        }

        return res;
    }
};
