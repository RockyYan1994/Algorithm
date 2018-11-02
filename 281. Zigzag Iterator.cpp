/*
	方法一：采用队列的方法，不断把iterator push进，每次遍历一次之后，pop。支持k个vector的操作。
*/

//version 1(20 ms)
class ZigzagIterator {
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator it = q.front().first;
        vector<int>::iterator it_end = q.front().second;
        q.pop();        
        if (it+1 != it_end) q.push(make_pair(it+1, it_end));
        return *it;        
    }

    bool hasNext() {
        return !q.empty();
    }
};


//version 2(12 ms)
class ZigzagIterator {
    std::vector<int> v;
    int cur;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    	cur = 0;
    	v.reserve(v1.size() + v2.size() - 1);
    	int n = max(v1.size(), v2.size());
    	for (int i=0; i<n; i++) {
    		if (i<v1.size()) v.push_back(v1[i]);
    		if (i<v2.size()) v.push_back(v2[i]);
    	}
    }

    int next() {
        return v[cur++];
    }

    bool hasNext() {
    	return cur < v.size();
    }
};
