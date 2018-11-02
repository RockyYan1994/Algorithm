/*
    采BFS的方法实现，
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> indegrees = cal_indegree(numCourses, prerequisites);
        
        queue<int> zeros;
        for(int i=0;i<indegrees.size();i++) {
            if(indegrees[i] == 0) zeros.push(i);
        }
        vector<int> res;
        while(!zeros.empty()) {
            int index = zeros.front();
            zeros.pop();
            res.push_back(index);
            for(auto elem : graph[index]) {
                indegrees[elem]--;
                if(indegrees[elem] == 0) zeros.push(elem);
            }
        }
        if(res.size() != indegrees.size()) return vector<int>();
        return res;
    }
    
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre:prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    } 
    vector<int> cal_indegree(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        for(auto pre:prerequisites) {
            indegrees[pre.first]++;
        }
        return indegrees;
    }
};