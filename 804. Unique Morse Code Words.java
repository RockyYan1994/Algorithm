/*

*/

//version 1()
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> set = new HashSet();
        for (String word : words) {
            StringBuilder sb = new StringBuilder();
            for (char ch : word.toCharArray()) {
                sb.append(dict[ch - 'a']);
            }
            set.add(sb.toString());
        }
        return set.size();
    }
}