/*

*/

//version 1(2 ms)
class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> res = new ArrayList();
        for (int i = 1; i <= n; i++) {
            StringBuilder ans = new StringBuilder();
            if (i % 3 == 0) {
                ans.append("Fizz");
            }
            if (i % 5 == 0) {
                ans.append("Buzz");                
            }
            if (ans.length() == 0) {
                ans.append(i);
            }
            res.add(ans.toString());            
        }
        return res;
    }
}