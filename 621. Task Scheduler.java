/*
	方法一：采用PriorityQueue，模拟每层构建的方式，计算最终结果。
	方法二：通过分析，先算出一共可能的idle——num然后通过剩余元素去减。
*/

//version 1(61 ms)
class Solution {
    public int leastInterval(char[] tasks, int n) {
        if (n == 0) return tasks.length;
        int[] cnts = new int[26];
        for (char ch : tasks) cnts[ch - 'A']++;
        Queue<Integer> taskWindow = new PriorityQueue<>(26, Collections.reverseOrder());
        for (int cnt : cnts) {
            if (cnt > 0) taskWindow.add(cnt);
        }
        int res = 0;
        while (!taskWindow.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            int i=0;
            while (i<=n) {
                if (!taskWindow.isEmpty()) {
                    if (taskWindow.peek() > 1) {
                        temp.add(taskWindow.poll() - 1);
                    } else {
                        taskWindow.poll();
                    }
                }
                res++;
                if (taskWindow.isEmpty() && temp.isEmpty()) return res;                
                i++;
            }
            for (int num : temp) taskWindow.add(num);                                                            
        }
        return res;
    }
}

//version 2(5 ms)
class Solution {
    public int leastInterval(char[] tasks, int n) {
        if (n == 0) return tasks.length;
        int[] map = new int[26];
        for (char task : tasks) map[task-'A']++;
        Arrays.sort(map);
        int max_val = map[25] - 1, idle_num = max_val * n;
        for (int i=24; i>=0&&map[i]>0; i--) {
            idle_num -= Math.min(max_val, map[i]);
        }
        return idle_num > 0 ? idle_num + tasks.length : tasks.length;
    }
}