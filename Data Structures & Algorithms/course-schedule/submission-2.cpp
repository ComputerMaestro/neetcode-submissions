/*
in this we can see a pattern where a course is a node and it is connected to another node based on the prerequiment
it is directional because the a prerequisite tells one node dependency on another in one way

if we a cycle in this , then it will not be possible to complete the courses 
to avoid repeated traversals we can maintain a visted array which will tell whether this node can be completed or not 
for every traversal starting from everynode we need to check if there is a cycle , if cycle then return fasle immeediately 

this will take O(n) where n is number of courses 
as every node will be travelled once 
for this we will need recursion 
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> pres(numCourses);
        for (vector<int> pre: prerequisites) {
            pres[pre[1]].push_back(pre[0]);
        }

        vector<bool> courseComp(numCourses, false);
        for (int c = 0; c < numCourses; c++) {
            if (!courseComp[c]) {
                vector<bool> visited(numCourses, false);
                if (!dfs(pres, courseComp, visited, c)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& pres, vector<bool>& courseComp, vector<bool>& visited, int course) {
        if (visited[course]) {
            return false;
        }
        if (courseComp[course]) {
            return true;
        }
        visited[course] = true;
        for(int c: pres[course]) {
            if (!dfs(pres, courseComp, visited, c)) {
                return false;
            }
        }
        visited[course] = false;
        courseComp[course] = true;
        return true;
    }
};
