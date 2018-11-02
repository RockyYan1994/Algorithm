/*
	方法一：采用buckets的方法来实现，
	方法二：采用priorityQueue按照frequency来保存频率。
*/


//version 1(13 ms)
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) map.put(num, map.getOrDefault(num, 0)+1);
        List<Integer>[] buckets = new List[nums.length+1];
        for (Map.Entry<Integer, Integer> pair : map.entrySet()) {
            if (buckets[pair.getValue()] == null) {
                buckets[pair.getValue()] = new ArrayList<>();
            }
            buckets[pair.getValue()].add(pair.getKey());
        }       
        List<Integer> res = new ArrayList<>();
        for (int pos = nums.length; pos>=0 && k>0; pos--) {
            if (buckets[pos] != null) {
                res.addAll(buckets[pos]);
                k -= buckets[pos].size();
            }
        }
        return res;
    }
}

//version 2(53 ms)
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) map.put(num, map.getOrDefault(num, 0)+1);
        PriorityQueue<Map.Entry<Integer, Integer>> fq = new PriorityQueue<Map.Entry<Integer, Integer>>(
            (a,b)->(b.getValue() - a.getValue()));
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) fq.add(entry);
        List<Integer> res = new ArrayList<>();
        while (res.size() < k) {
            res.add(fq.poll().getKey());
        }
        return res;
    }
}