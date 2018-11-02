/*
	方法一：用priorityQueue实现。通过创建一个Node类型，保存index和temp，在priorityQueue中按照temp排序。当当前的节点的temp > PQ定点的temp，就输出。
	方法二：用Stack，从后往前，
*/

//version 1(77 ms)
class Solution {
    public int[] dailyTemperatures(int[] T) {
        if (T.length == 0) return null;
        int[] res = new int[T.length];
        Queue<Node> Q = new PriorityQueue<>((a,b) -> (a.temp - b.temp));
        for (int i=0; i<T.length; i++) {
            while (!Q.isEmpty() && T[i] > Q.peek().temp) {
                Node old = Q.poll();
                res[old.index] = i - old.index;
            }
            Q.add(new Node(i, T[i]));
        }
        return res;
    }
    
    class Node {
        int index;
        int temp;
        Node(int index, int temp) {
            this.index= index;
            this.temp = temp;
        }
    }
}

//version 2()
class Solution {
    public int[] dailyTemperatures(int[] T) {
        if (T.length == 0) return null;
        int[] res = new int[T.length];
        Stack<Integer> S = new Stack<>();
        for (int i=T.length-1; i>=0; i--) {
            while (!S.isEmpty() && T[i] >= T[S.peek()]) {
                S.pop();
            }
            res[i] = S.isEmpty() ? 0 : S.peek() - i;
            S.push(i);
        }
        return res;
    }
}