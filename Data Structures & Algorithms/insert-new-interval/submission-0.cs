public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {

        var result = new List<int[]>();
        int i = 0;
        int n = intervals.Length;

        //Phase 1:
        // add intervals that end before newInterval start
        // intervals[i][1] accesses the end times, newInterval[0] accesses the start time
        while(i < n && intervals[i][1] < newInterval[0])
        {
            result.Add(intervals[i]);
            i++;
        }

        // Phase 2:
        // Merge overlapping intervals
        //intervals[i][0] accesses the start times, newInterval[1] accesses the end time
        while(i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = Math.Min(intervals[i][0], newInterval[0]);
            newInterval[1] = Math.Max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.Add(newInterval);

        // Phase 2:
        // Add intervals that start after the new interval ends
        // basically just adding whatever is left
        while(i < n)
        {
            result.Add(intervals[i]);
            i++;
        }

        return result.ToArray();
    }
}
