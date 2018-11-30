/*

*/

//version 1(1 ms)
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        int cnt = 0;
        List<String> res = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (sb.length() == 0) {
                sb.append(words[i]);
            } else if (sb.length() + words[i].length() + 1<= maxWidth) {
                sb.append(" " + words[i]);
            } else {
                res.add(sb.toString());
                sb.setLength(0);
                sb.append(words[i]);
            }
        }
        if (sb.length() != 0) {
            res.add(sb.toString());
        }
        for (int i = 0; i < res.size() - 1; i++) {
            res.set(i, fully(res.get(i), maxWidth));
        }
        res.set(res.size() - 1, left(res.get(res.size() - 1), maxWidth));
        return res;
    }
    
    private String fully(String str, int maxWidth) {
        StringBuilder sb = new StringBuilder();
        String[] words = str.split(" ");
        int len = 0;
        for (String word : words) {
            len += word.length();
        }
        int spaces = words.length == 1 ? maxWidth - len : (maxWidth - len) / (words.length - 1);
        // System.out.println(spaces);
        int remains = words.length == 1 ? 0 : maxWidth - len - spaces * (words.length - 1);
        sb.append(words[0]);
        for (int i = 1; i < words.length; i++) {            
            sb.append(getSpaces(spaces + (remains <= 0 ? 0 : 1)));
            sb.append(words[i]);
            remains--;
        }
        return words.length == 1 ? sb.append(getSpaces(spaces)).toString() : sb.toString();
    }
    
    private String left(String str, int maxWidth) {
        StringBuilder sb = new StringBuilder();
        String[] words = str.split(" ");
        for (int i = 0; i < words.length; i++) {            
            sb.append(words[i] + " ");
        }
        if (sb.length() < maxWidth) {
            sb.append(getSpaces(maxWidth - sb.length()));
        }
        return sb.length() > maxWidth ? sb.substring(0, maxWidth).toString() : sb.toString();
    }
    
    private String getSpaces(int n) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0 ; i < n ; i++) {
            sb.append(" ");
        }
        return sb.toString();
    }
}