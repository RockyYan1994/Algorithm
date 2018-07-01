/*
	这个问题主要是复制每个node，但是需要避免重复复制的问题，需要采用一个map来避免重复的问题。
	1，采用DFS的方法来实现。
	2，采用BFS的方法来实现。
*/	

//version 1(20 ms)
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        if( mp.find(node) == mp.end() ){
            mp[node] = new UndirectedGraphNode(node->label);
            for(auto neighbor : node->neighbors){
                mp[node]->neighbors.push_back( cloneGraph(neighbor) );
            }
        }
        return mp[node];
    }
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};

//version 2(28 ms)
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        queue<UndirectedGraphNode*> q;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        mp[node] = ret;
        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for(auto neighbor : cur->neighbors ){
                if(mp.find(neighbor) == mp.end()){
                    mp[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push( neighbor );
                }
                mp[cur] -> neighbors.push_back( mp[neighbor] );
            }
        }
        return ret;
    }
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
};