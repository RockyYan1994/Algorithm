/*

*/

//version 1(3 ms)
class Solution {
    public int[] anagramMappings(int[] A, int[] B) {        
        Map<Integer, Integer> positions = new HashMap<Integer, Integer>();
        if (A.length == 0 || B.length == 0) return null;
        for (int i=0; i<B.length; i++) {
            positions.put(B[i], i);
        }
        int[] res = new int[A.length];
        for (int i=0; i<A.length; i++) {
            res[i] = positions.get(A[i]);
        }
        return res;
    }
}