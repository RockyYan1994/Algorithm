/*
	1，BFS，首先把prerequisites转换形式，然后计算每个节点的入度，最后遍历入度为0的节点。
	2，相对于第一个方法，优化了在遍历过程中每次需要遍历数组找到入度为0的过程，在减少入度的同时将入度为0的点加入queue。
	3，DFS,通过onpath和visited分别表示正在进行和已经遍历。
*/

//version 1(30ms)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> degree = makeInorder(numCourses, graph);

        for(int i=0;i<numCourses;i++){
            int j=0;
            for(j=0;j<numCourses;j++)
                if(degree[j] == 0) break;
            if(j == numCourses) return false;
            degree[j] = -1;
            for( auto vertex : graph[j])
                degree[vertex]--;
            
        }
        return true;
    }
    
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    
    vector<int> makeInorder(int numCourses, vector<unordered_set<int>>& graph){
        vector<int> degree(numCourses,0);
        for(auto set : graph){
            for(int vertex : set){
                degree[vertex]++;
            }
        }
        return degree;
    }
};


//version 2(17 ms)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> degree = makeInorder(numCourses, graph);
        int count = 0;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(degree[i] == 0) q.push(i);
        while(!q.empty()){
            int j = q.front();
            q.pop();
            degree[j] = -1;
            for( int vertex : graph[j])
                if(--degree[vertex] == 0) q.push(vertex);
            count++;
        }
        return count == numCourses;
    }
    
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    
    vector<int> makeInorder(int numCourses, vector<unordered_set<int>>& graph){
        vector<int> degree(numCourses,0);
        for(auto set : graph){
            for(int vertex : set){
                degree[vertex]++;
            }
        }
        return degree;
    }
};


//version 3(from jianchao.li.fighter)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
};



