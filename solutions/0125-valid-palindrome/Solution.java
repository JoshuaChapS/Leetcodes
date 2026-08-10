public class Solution {
    public boolean isPalindrome(String s) {
        int izq = 0, der = s.length() - 1;
        while (izq <= der) {
            while (izq <= der && !Character.isLetterOrDigit(s.charAt(izq))) izq++;
            while (izq <= der && !Character.isLetterOrDigit(s.charAt(der))) der--;
            if (izq > der) return true;
            if (Character.toLowerCase(s.charAt(izq)) !=
                Character.toLowerCase(s.charAt(der))) return false;
            izq++; der--;
        }
        return true;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.isPalindrome("A man, a plan, a canal: Panama")); // true
        System.out.println(s.isPalindrome("race a car"));                     // false
        System.out.println(s.isPalindrome(" "));                              // true
        System.out.println(s.isPalindrome("0P"));                             // false
    }
}
