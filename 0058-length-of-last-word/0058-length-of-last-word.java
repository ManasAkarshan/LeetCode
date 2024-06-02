class Solution {
    public int lengthOfLastWord(String s) {
        String sb=s.trim();
        int j=sb.length()-1;
        int count=0;
        while(j>=0 && sb.charAt(j)!=' '){
            count++;
            j--;
        }
        return count;
    }
}