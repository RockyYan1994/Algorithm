/*
	方法一：每次更改完之后，indexes后面的index，如果比当前的大，就更新offset，
*/

//version 1()
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int off = 0, n = S.length(), m = sources.length;
        StringBuilder sb = new StringBuilder(S);
        for (int k = 0; k < m; k++) {
            if (sb.substring(indexes[k], indexes[k] + sources[k].length()).equals(sources[k])) {
                sb.replace(indexes[k], indexes[k] + sources[k].length(), targets[k]);
                off = targets[k].length() - sources[k].length();
                //System.out.println(off);
                for (int j = k+1; j < m; j++) {
                    if (indexes[k] < indexes[j]) {
                        indexes[j] += off;
                    }
                }
            }
        }
        return sb.toString();
    }
}

//version 2()
class Solution {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        int off = 0, n = S.length(), m = sources.length;
        StringBuilder sb = new StringBuilder(S);
        List<int[]> L = new ArrayList<>();
        for (int i = 0; i < m; i++) L.add(new int[]{indexes[i], i});
        Collections.sort(L, (a, b) -> (b[0] - a[0]));
        for (int[] pair : L) {
            //System.out.println(pair[0] + ", " + pair[1]);
            if (sources[pair[1]].equals(sb.substring(pair[0], pair[0] + sources[pair[1]].length()).toString())) {
                sb.replace(pair[0], pair[0] + sources[pair[1]].length(), targets[pair[1]]);
            }
        }
        return sb.toString();
    }
}