/*

*/

//version 1(32 ms)
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        StringBuilder[] sbs = new StringBuilder[numRows];
        for (int i=0; i<numRows; i++) sbs[i] = new StringBuilder();
        for (int i=0; i<s.length(); i++) {
            int row = i % (2 * numRows - 2);
            row = row >= numRows ? 2*numRows-2-row : row;
            sbs[row].append(s.charAt(i));            
        }        
        StringBuilder res = new StringBuilder();
        for (int i=0; i<numRows; i++) res.append(sbs[i].toString());
        return res.toString();
    }
}