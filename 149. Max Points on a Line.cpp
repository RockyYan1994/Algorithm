/*
	这个题的方法通过
*/

//version 1(9 ms)
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        map<pair<int,int>, int> slopes;
        int maxPoint = 0;
        for(int i=0;i<points.size();i++){
            slopes.clear();
            int duplicates = 1;
            for(int j=i+1;j<points.size();j++){
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                if(x == 0 && y == 0) {
                    duplicates++;
                    continue;
                }
                int div = gcd(x,y);
                slopes[make_pair(x/div,y/div)]++;
            }
            
            maxPoint = max(maxPoint, duplicates);
            for(auto slope : slopes){
                if(slope.second + duplicates > maxPoint) maxPoint = slope.second + duplicates;
            }
        }
        return maxPoint;
    }
    
private:
    //greatest common divisor
    int gcd(int num1, int num2){
        while(num2){
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
};