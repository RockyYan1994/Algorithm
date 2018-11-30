/*
	方法一：思路就是利用回文的特性，但是要注意是最近的，如果直接反转和原string相同，或者有更小的情况，因此需要计算前半部分+1或者-1的情况。
	要注意在+1或者-1会遇到进位或者去掉头部的情况，需要特殊处理。
*/

//version 1()
class Solution {
    public String nearestPalindromic(String n) {
        if ("1".equals(n)) return "0";
        String s = buildFirstHalfMirrorString(n);
        long diff = s.equals(n) ? Integer.MAX_VALUE : Math.abs((Long.parseLong(s) - Long.parseLong(n)));
        
        StringBuilder sb1 = new StringBuilder(n);
        int mid = (sb1.length() - 1) / 2;
        while (mid > 0 && sb1.charAt(mid) == '0') {
            sb1.setCharAt(mid--, '9');
        }
        if (mid == 0 && sb1.charAt(mid) == '1') {
            sb1.deleteCharAt(mid);
            // 需要处理像 "1000" 的情况， 需要把中间的数变成9， 而像"10" 的情况，需要变成“9”
            sb1.setCharAt((sb1.length() - 1)/2, '9');
        } else {
            sb1.setCharAt(mid, (char)(sb1.charAt(mid) - 1));
        }
        String s1 = buildFirstHalfMirrorString(sb1.toString());
        long diff1 = Math.abs(Long.parseLong(n) - Long.parseLong(s1));
        
        StringBuilder sb2 = new StringBuilder(n);
        mid = (sb2.length() - 1) / 2;
        while (mid > 0 && sb2.charAt(mid) == '9') {
            sb2.setCharAt(mid--, '0');
        }
        if (mid == 0 && sb2.charAt(mid) == '9') {
            sb2.setCharAt(0, '0');
            sb2.insert(0, '1'); 
        } else {
            sb2.setCharAt(mid, (char)(sb2.charAt(mid) + 1));
        }
        String s2 = buildFirstHalfMirrorString(sb2.toString());
        long diff2 = Math.abs(Long.parseLong(n) - Long.parseLong(s2));
        
        //System.out.println("diff: " + diff + ", diff1: " + diff1 + ", diff2: " + diff2);
        
        if (diff1 <= diff && diff1 <= diff2) {          
            return s1;
        } else if (diff <= diff2) {
            return s;
        } else {            
            return s2;
        }
    }
    
     private String buildFirstHalfMirrorString(String old) {
        String s = old.substring(0, old.length() / 2);
        return s + (old.length() % 2 == 0 ? "" : old.charAt(old.length()/2)) + new StringBuilder(s).reverse().toString(); 
    }
}