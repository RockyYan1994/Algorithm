/*

*/

//vesion 1(43 ms)
class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        Stack<Integer> stack = new Stack<>();
        int[] times = new int[n];
        int cur = -1, prev = 0;
        for (String log : logs) {
            String[] parsedLog = log.split(":");
            if (parsedLog[1].equals("end")) {
                stack.pop();
                int now = Integer.valueOf(parsedLog[2]);
                times[cur] += now - prev + 1;
                prev = now + 1;   
                if (!stack.isEmpty()) cur = stack.peek();
                else cur = -1;
            } else {
                if (cur == -1) {
                    cur = Integer.valueOf(parsedLog[0]);
                    stack.push(cur);
                    prev = Integer.valueOf(parsedLog[2]);
                    continue;
                } 
                int now = Integer.valueOf(parsedLog[2]);
                times[cur] += now - prev;
                cur = Integer.valueOf(parsedLog[0]);
                stack.push(cur);
                prev = now;
            }
        }
        return times;
    }    
}