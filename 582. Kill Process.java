/*

*/

//version 1()
class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Set<Integer> killed = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(kill);
        killed.add(kill);
        List<Integer> res = new ArrayList<>();
        res.add(kill);
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            for (int i = 0; i < ppid.size(); i++) {
                if (ppid.get(i) == cur && !killed.contains(pid.get(i))) {
                    res.add(pid.get(i));
                    queue.add(pid.get(i));
                    killed.add(pid.get(i));
                }
            }
        }
        return res;
    }
}

//version 2(53 ms)
class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Map<Integer, List<Integer>> children = new HashMap<>();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < pid.size(); i++) {
            if (!children.containsKey(ppid.get(i))) {
                children.put(ppid.get(i), new ArrayList<>());
            }
            children.get(ppid.get(i)).add(pid.get(i));
        }
        queue.add(kill);        
        List<Integer> res = new ArrayList<>();
        res.add(kill);
        while (!queue.isEmpty()) {
            List<Integer> ids = children.get(queue.poll());
            if (ids == null) continue;
            res.addAll(ids);
            queue.addAll(ids);
        }
        return res;
    }
}