/*
	方法一：参考solution，通过一个Interval结构记录，用PQ实现，需要注意边界变量。
*/

//version 1(70 ms)
class ExamRoom {
    
    PriorityQueue<Interval> Q;
    
    private int n;
    
    class Interval {
        int l, r, dist;
        public Interval(int l, int r) {
            this.l = l;
            this.r = r;
            if (l == -1) {
                dist = r;
            } else if (r == n) {
                dist = r - 1 - l;
            } else {
                dist = (r - l) / 2;
            }
        }
    }

    public ExamRoom(int N) {
        Q = new PriorityQueue<>((a,b) -> a.dist == b.dist ? a.l - b.l : b.dist - a.dist);
        n = N;
        Q.add(new Interval(-1, N));
    }
    
    public int seat() {
        Interval cur = Q.poll();
        int pos = 0;
        if (cur.l == -1) {
            pos = 0;
        } else if (cur.r == n) {
            pos = n-1;
        } else {
            pos = cur.l + (cur.r - cur.l) / 2;
        }
        Q.add(new Interval(cur.l, pos));
        Q.add(new Interval(pos, cur.r));
        return pos;
    }
    
    public void leave(int p) {
        Interval head = null, tail = null;
        for (Interval i : Q) {
            if (i.l == p) tail = i;
            if (i.r == p) head = i;
            if (tail != null && head != null) break;
        }
        Q.remove(head);
        Q.remove(tail);
        Q.add(new Interval(head.l, tail.r));
    }
}

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */