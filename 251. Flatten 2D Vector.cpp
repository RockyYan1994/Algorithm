/*
	方法一：先转换成一个一位数组
	方法二：通过iterator记录行数，int j记录列。
*/

//version 1(8 ms)
class Vector2D {
    vector<int> vec1d;
    int ptr;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        ptr = 0;
        int m = vec2d.size();
        for (int i=0; i<m; i++) {
            vec1d.insert(vec1d.end(), vec2d[i].begin(), vec2d[i].end());
        }
    }

    int next() {
        if (hasNext())
            return vec1d[ptr++];
    }

    bool hasNext() {
        return ptr < vec1d.size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

//version 2(8 ms)
class Vector2D {
    vector<vector<int>>::iterator i, iEnd;
    int j;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        iEnd = vec2d.end();
        j = 0;
    }

    int next() {
        if (hasNext())
            return (*i)[j++];
        return -1;
    }

    bool hasNext() {
        while(i != iEnd && j == (*i).size()) {
            i++;
            j = 0;
        }
        return i != iEnd;
    }
};