// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: 2, [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
//              course 0. So the correct course order is [0,1] .
// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> indegree(numCourses, 0);
    vector<int> ans;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]] += 1;
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int temp = q.front();
        ans.push_back(temp);
        q.pop();
        for (int i = 0; i < graph[temp].size(); i++)
        {
            indegree[graph[temp][i]] -= 1;
            if (indegree[graph[temp][i]] == 0)
            {
                q.push(graph[temp][i]);
            }
        }
    }
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] != 0)
        {
            return vector<int>(0);
        }
    }
    return ans;
}

int main()
{
    return 0;
}