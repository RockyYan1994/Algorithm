/*

*/

//version 1(19 ms)
class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> S = new Stack<Integer>();
        for (int ast : asteroids) {
            if (ast > 0) {
                S.add(ast);                
            } else if (ast < 0) {
                boolean coll = false;                
                while (!S.isEmpty()) {
                    int top = S.peek();
                    if (top > 0) {
                        if (top + ast > 0) {
                            coll = true;
                            break;
                        } else if (top + ast == 0) {
                            S.pop();
                            coll = true;
                            break;
                        } else {
                            S.pop();
                        }
                    } else {                        
                        break;
                    }
                }
                if (!coll) {
                    S.add(ast);
                }
            }
        }
        if (S.isEmpty()) {
            return new int[]{};
        }
        int[] res = new int[S.size()];
        for (int i = S.size()-1; i>=0; i--) {
            res[i] = S.pop();
        }
        return res;
    }
}