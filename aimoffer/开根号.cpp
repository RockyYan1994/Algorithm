/**
author: JUCAI YAN
给定一个数，计算其开根号的结果：方法一，二分查找，方法二：牛顿法(在求根号的时候并不会遇到不收敛的问题，但是在牛顿法在处理一些别的函数时可能会遇到抖动，不收敛等
问题)，在这个问题上牛顿法具有更好的表现。
reference: https://www.zhihu.com/question/20690553
*/

#include<iostream>
#include<iomanip>
#include<cmath>     // std::fabs

using namespace std;

double sqrt(double x, double accuracy);
double sqrt2(double x, double accuracy);
double myAbs(double input);

int main(int argc, char const *argv[])
{
	double input;
	cin >> input;
	cout<< "The square root of "<< input << " is " << setprecision(3) << sqrt2(input, 1.0e-10) <<endl;;
	return 0;
}

//version 1
double sqrt(double x, double accuracy){
	if( x<0 ) return -1;
	double low   = 0.0;
	double height = x;
	double ret = 0.0;
	while(low<height){
		double mid = low + (height-low)/2;
		ret = mid;
		double temp = mid * mid;
		if(fabs(temp - x) < accuracy) return ret;
		else if(temp < x) low = mid;
		else height = mid;
	}
	return -1;
}

//version 2
double sqrt2(double a, double accuracy){
	if(a<0) return -1;
	if(a == 0) return 0;
	double x = 1.0;
	while(myAbs(x*x - a) > accuracy){
		x = (x + a/x)/2.0;
	}
	return x;
}

double myAbs(double input)
{
	return input>0 ? input : -input;
}
