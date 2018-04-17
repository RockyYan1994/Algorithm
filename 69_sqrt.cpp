/*
	first
	首先想到使用最简单的方法，采用从0开始，依次+1直到平方的值大于x，然后返回n-1.一开始采用n*n 的方法，但是由于溢出的关系，不能够正确运行，
	然后换成了x/n<n的方法判断，成功，但是运行速度非常慢.
	查看过discussion之后发现可以采用二分法的思想来查找n，此外还可以使用newton法实现。
	Newton's Method（https://zh.wikipedia.org/wiki/%E7%89%9B%E9%A1%BF%E6%B3%95）
*/

//version 1(167 ms)
class Solution {
public:
    int mySqrt(int x) {
        int n=1;
        while(true){
            if(x/n<n) break;
            n++;
        }
        return n-1;
    }
};

//version 2(16 ms)
class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int l=0,h=x,mid;
        while(l<h){
            mid = l+(h-l)/2;
            if(x/mid>=mid) l = mid+1;
            else h = mid;
        }
        return h-1;
    }
};