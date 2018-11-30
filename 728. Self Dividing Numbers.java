/*

*/

//version 1(5 ms)
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {        
        List<Integer> res = new ArrayList();
        for (int i = left; i <= right; i++) {
            if (valid(i)) res.add(i);
        }
        return res;
    }
    
    private boolean valid(int num) {
        int temp = num;
        while (temp != 0) {
            if (temp % 10 == 0 || num % (temp % 10) != 0) {
                return false;
            }
            temp /= 10;
        }
        return true;
    }
}