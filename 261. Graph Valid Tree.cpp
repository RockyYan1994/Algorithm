/*
	方法一：通过UNION-FINF实现
	方法二：通过没有递归的UNION-FIND实现。
*/

//version 1(4ms)
class Solution {
public:
    // use UNION-FIND
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> vertices(n, -1);
        for (int i=0; i<edges.size(); i++) {
            int x = find(vertices, edges[i].first);
            int y = find(vertices, edges[i].second);
            
            if (x == y) return false;
            vertices[x] = y;
        }
        return edges.size() == n-1;
    }
    
    int find(vector<int>& vertices, int i) {
        if (vertices[i] == -1) return i;
        return find(vertices, vertices[i]);
    }
};

//version 2(4 ms)
class Solution {
public:
    // use UNION-FIND
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> vec(n, 0);
        if (edges.size() != vec.size()-1) return false;
        for (int i=0; i<vec.size(); i++) vec[i] = i;
        for (int i=0; i<edges.size(); i++) {
            int a = edges[i].first;
            int b = edges[i].second;
            while(a != vec[a]) a = vec[a];
            while(b != vec[b]) b = vec[b];            
            if (a == b) {
                return false;   
            }
            vec[a] = b;
        }
        return true;
    }
};