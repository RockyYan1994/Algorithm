/*

*/

//version 1(5 ms)
class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String> alphas = new ArrayList(), nums = new ArrayList();
        List<String> res = new ArrayList();
        category(alphas, nums, logs);
        Collections.sort(alphas, new Comparator<String>() {
            public int compare(String a, String b) {
                int res = a.substring(a.indexOf(" ")+1).compareTo(b.substring(b.indexOf(" ")+1));
                if (res != 0) {
                    return res; 
                } else {
                    return a.substring(0, a.indexOf(" ")).compareTo(b.substring(0, b.indexOf(" ")));
                }
            }
        });
        res.addAll(alphas);
        res.addAll(nums);
        
        return res.toArray(new String[res.size()]);
    }    
    
    private void category(List<String> alphas, List<String> nums, String[] logs) {
        for (String log : logs) {
            int i = log.indexOf(" ");
            if (log.charAt(i + 1) >= '0' && log.charAt(i + 1) <= '9') {
                nums.add(log);
            } else {
                alphas.add(log);
            }
        }        
    }
}