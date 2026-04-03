class Solution {

    //map each course to its prereqs
        unordered_map<int, vector<int>> preMap;
        //store all courses visited along the DFS path
        unordered_set<int> visited;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        for(int i = 0; i < numCourses; i++)
        {
            preMap[i] = {}; // set every value to an empty list
        }
        for(const auto& prereq : prerequisites)
        {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        for(int c = 0; c < numCourses; c++)
        {
            if(!dfs(c))
            {
                return false;
            }
        }

        return true;
    }

    bool dfs(int crs)
    {
        if(visited.count(crs))
        {
            // cylce has been detected
            return false;
        }
        if(preMap[crs].empty())
        {
            return true;
        }

        visited.insert(crs);
        for(int pre:preMap[crs])
        {
            if(!dfs(pre))
            {
                return false;
            }
        }

        visited.erase(crs);
        preMap[crs].clear();
        return true;
    }
};
