/*
DFS traversal:
In this problem we have this dependencies , for this we can solve it by traversing these dependencies from each node in DFS and check if all can be done without making a circular dependency

in this recursive calls will be needed 
time complexity will be O(c * n) c in num courses and n is length of prequisites
space complexity will be O(c * n) for all node and edges in worst case due to recursion and making visited nodes and tracking the possibility of it being done 


Topological Sort:
make edges from dependency to dependent courses 

then we will start traversing from the courses which are already completed (which do not have any prerequisites ) and we will keep a count of dependencies for each course (in degree) of that course
and whenever a course indegree becomes zero we will start traversing that node or will put it is queue

if nodes are remaining but queue is empty , that means their is a cycle and then we will have to return empty array

time complexity will be O(c * n) again but this time their is not coming back for recursion and that is saved and make this a bit faster
space complexity will be O(c * n) for queue space
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dependencies(numCourses);
        vector<int> indegree(numCourses, 0);
        for (vector<int> d : prerequisites) {
            dependencies[d[1]].push_back(d[0]);
            indegree[d[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while(!q.empty()) {
            int d = q.front();
            q.pop();
            order.push_back(d);

            for (int c : dependencies[d]) {
                indegree[c] -= 1;
                if (indegree[c] == 0) {
                    q.push(c);
                }
            }
        }
        if (order.size() < numCourses) {
            return {};
        }
        return order;
    }
};
