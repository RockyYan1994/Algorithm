/*

*/

//version 1(15 ms)
class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        Queue<int[]> Q = new LinkedList<>();
        int bar = 0, n = price.size();
        for (int i = 0; i < needs.size(); i++) {
            bar += needs.get(i) * price.get(i);
        }
        Q.add(new int[n+1]);        
        while (!Q.isEmpty()) {
            int[] cur = Q.poll();
            for (int i = 0; i < special.size(); i++) {
                int[] temp = cur.clone();
                boolean valid = true;
                for (int k = 0; k < n; k++) {
                    temp[k] += special.get(i).get(k);
                    if (temp[k] > needs.get(k)) {
                        valid = false;
                        break;
                    }
                }
                temp[n] += special.get(i).get(n);
                if (valid && temp[n] < bar) {
                    int amount = temp[n];
                    for (int k = 0; k < n; k++) {
                        amount += (needs.get(k) - temp[k]) * price.get(k);
                    }           
                    bar = Math.min(amount, bar);
                    Q.add(temp);
                }
            }
        }
        return bar;        
    }
}