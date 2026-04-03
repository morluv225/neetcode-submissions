class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int, vector<int>> preMap;
        for(const auto& prereq:prerequisites)
        {
            preMap[prereq[0]].push_back(prereq[1]); // map prereqs to course
        }

        vector<int> output;
        unordered_set<int> visit;
        unordered_set<int> cycle;

        for(int c = 0; c < numCourses; c++)
        {
            if(!dfs(c, preMap, visit, cycle, output))
            {
                return {};
            }
        }

        return output;
    }

    bool dfs(int crs, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visit, 
    unordered_set<int>&cycle, vector<int>& output)
    {
        if(cycle.count(crs))
        {
            return false;
        }
        
        if(visit.count(crs))
        {
            return true;
        }

        cycle.insert(crs);
        if(preMap.count(crs))
        {
            for(int pre : preMap[crs])
            {
                if(!dfs(pre, preMap, visit, cycle, output))
                {
                    return false;
                }
            }
        }

        cycle.erase(crs);
        visit.insert(crs);
        output.push_back(crs);
        return true;
    }
};
