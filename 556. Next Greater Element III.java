class Solution {
    public int nextGreaterElement(int n) {
        char[] C = ("" + n).toCharArray();
        int i = C.length-2;
        while(i>=0 && C[i] >= C[i+1]) {
            i--;
        }
        if (i < 0) return -1;        
        int j = C.length - 1;
        while (j >= i && C[j] <= C[i]) {
            j--;
        }
        if (i == j) {
            return -1;
        }
        swap(C, i, j);
        reverse(C, i+1);
        try {
            return Integer.valueOf(new String(C));   
        } catch(Exception e) {
            return -1;
        } 
    }
    
    private void swap(char[] C, int i, int j) {
        char temp = C[i];
        C[i] = C[j];
        C[j] = temp;
    }
    
    private void reverse(char[] C, int start) {
        int i = start, j = C.length - 1;
        while (i < j) {
            swap(C, i++, j--);
        }
    }
}