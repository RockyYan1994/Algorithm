/*
	方法一：采用UNION-Find， 注意又个地方，就是第二个循环，确保成功UNION两个集合。
*/

//version 1(67 ms)
class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        Map<String, String> M = new HashMap<>();
        Map<String, String> owner = new HashMap<>();        
        Map<String, TreeSet<String>> U = new HashMap<>();
        for (List<String> account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                M.put(account.get(i), account.get(1));
                owner.put(account.get(i), account.get(0));
            }
        }
        for (List<String> account : accounts) {
            String parent = find(M, account.get(1));
            for (int i = 2; i < account.size(); i++) {
                M.put(find(M,account.get(i)), parent);
            }
        }
        
        for (List<String> account : accounts) {
            String parent = find(M, M.get(account.get(1)));
            //System.out.println(parent);
            if (!U.containsKey(parent)) {
                U.put(parent, new TreeSet<>());
            }
            for (int i = 1; i < account.size(); i++) {
                U.get(parent).add(account.get(i));
            }
        }
        List<List<String>> res = new ArrayList<>();
        for (String parent : U.keySet()) {
            List<String> temp = new ArrayList<>(U.get(parent));
            temp.add(0, owner.get(parent));
            res.add(temp);
        }
        return res;
    }
    
    private String find(Map<String, String> M, String email) {
        if (M.get(email).equals(email)) {
            return email;            
        } 
        String newParent = find(M, M.get(email));
        M.put(email, newParent);
        return newParent;
    }
}