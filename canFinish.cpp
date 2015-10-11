#include "common.h"
//not checked yet
/*
 * There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses == 0 || prerequisites.size() == 0)
            return true;
        vector<int > depend(numCourses, 0);
        vector<vector<int>> rdepend(numCourses, vector<int>{});
        for(auto& item: prerequisites){
            int node1 = item.first;
            int node2 = item.second;
            depend[node1] ++;
            rdepend[node2].push_back(node1);
        }
        vector<int>::iterator it;
        while( ( it = find(depend.begin(), depend.end(), 0)) != depend.end() ){
            int node = distance(depend.begin(), it);
            *it = -1;
            auto& rv = rdepend[node];
            for(auto n: rv){
                depend[n] --;
            }
        }

        it = find_if(depend.begin(), depend.end(), [](int i ){return i != -1;});
        return it == depend.end();
    }
};

int main() {
    vector<pair<int,int>> data;
    data.emplace_back(1, 0);
    cout << boolalpha << Solution().canFinish(2, data);
    return 1;
}