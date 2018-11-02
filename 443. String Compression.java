
//version 1(5 ms)
class Solution {
    public int compress(char[] chars) {
        if (chars.length == 0) return 0;
        char last = chars[0];
        int cnt = 1, idx = 0, i;
        for (i=1; i<chars.length; i++) {
            if (chars[i] != chars[i-1]) {
                chars[idx++] = chars[i-1];
                if (cnt != 1) {
                    String temp = String.valueOf(cnt);
                    for (int j=0; j<temp.length(); j++) {
                        chars[idx++] = temp.charAt(j);
                    }
                }
                cnt = 1;
            } else {
                cnt++;
            }
        }
        chars[idx++] = chars[chars.length-1];
        if (cnt != 1) {
            String temp = String.valueOf(cnt);
            for (int j=0; j<temp.length(); j++) {
                chars[idx++] = temp.charAt(j);
            }
        }
        return idx;
    }
}

//version 2(5 ms)
class Solution {
    public int compress(char[] chars) {
        if (chars.length == 0) return 0;
        char last = chars[0];
        int cnt = 0, idx = 0, i;
        for (i=0; i<chars.length; i++) {
            cnt++;
            if (i == chars.length-1 || chars[i] != chars[i+1]) {                
                chars[idx++] = chars[i];
                if (cnt != 1) {                    
                    for (char ch : ("" + cnt).toCharArray()) {
                        chars[idx++] = ch;
                    }
                }
                cnt = 0;
            }
        }
        return idx;
    }
}