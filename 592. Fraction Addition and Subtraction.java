/*
	方法一：采用Scanner，然后每次读区一个数字的方法实现。
*/

//version 1()
class Solution {
    public String fractionAddition(String expression) {
        Scanner sc = new Scanner(expression).useDelimiter("/|(?=[+-])");
        int A = 0, B = 1;
        while (sc.hasNext()) {
            int a = sc.nextInt(), b = sc.nextInt();
            A = A * b + B * a;
            B *= b;
            int g = gcd(A, B);
            A /= g;
            B /= g;
        }          
        return A + "/" + B;
    }
    
    private int gcd(int a, int b) {
        return a == 0 ? Math.abs(b) : gcd(b % a, a);
    }
}