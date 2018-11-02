/*

*/

//version 1()
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        if (buildings.empty()) return res;
        vector<pair<int, int>> heights;
        int n = buildings.size();
        for (int i=0; i<n; i++) {
        	heights.push(make_pair(buildings[i][0]), -buildings[i][2]);
        	heights.push(make_pair(buildings[i][1]), buildings[i][2]);
        }
        sort(heights.begin(), heights.end(), [] (pair<int, int> a, pair<int, int> b) {
        	if (a.first != b.first) return a.first - b.first;
        	return a.second - b.second;
        })
        
    }
};