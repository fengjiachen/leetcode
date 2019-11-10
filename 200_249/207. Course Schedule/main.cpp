// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

// Example 1:

// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: 2, [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses, vector<int>(0));
    vector<int> indegree(numCourses, 0);
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
            return false;
        }
    }
    return true;
}

int main()
{
}