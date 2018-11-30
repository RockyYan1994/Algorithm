/*

*/

//version 1(72 ms)
class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (String path : paths) {
            String[] files = path.split(" ");
            for (int i = 1; i < files.length; i++) {
                String[] file = files[i].split("[()]");
                String value = files[0] + "/" + file[0];
                String key = file[1];
                if (!map.containsKey(key)) {
                    map.put(key, new ArrayList<>());
                }
                map.get(key).add(value);
            }
        }
        List<List<String>> res = new ArrayList<>();
        for (String file : map.keySet()) {
            if (map.get(file).size() > 1)
                res.add(map.get(file));
        }
        return res;
    }
}