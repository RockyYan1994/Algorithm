/*
	方法一：采用一个priorityQueue，
*/

//version 1(5 ms)
class Solution {
    public int thirdMax(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        PriorityQueue<Integer> Q = new PriorityQueue<>();
        for (int num : nums) {
            if (Q.contains(num)) {
                continue;
            }
            Q.add(num);
            if (Q.size() > 3) {
                Q.poll();
            }
        }
        int res = 0;
        if (Q.size() == 3) {
            res = Q.poll();
        } else {
            while (!Q.isEmpty()) {
                res = Q.poll();
            }
        }
        return res;
    } 
}

//version 2()
class Solution {
    public int thirdMax(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        Integer A = null;
        Integer B = null;
        Integer C = null;
        for (Integer num : nums) {
            if (num.equals(A) || num.equals(B) || num.equals(C)) {
                continue;   
            }
            if (A == null || A < num) {
                C = B;
                B = A;
                A = num;
            } else if (B == null || B < num) {
                C = B;
                B = num;
            } else if (C == null || C < num) {
                C = num;
            }
       }
        return C == null ? A : C;
    } 
}