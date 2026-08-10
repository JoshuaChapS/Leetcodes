import java.util.*;

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groups = new HashMap<>();
        for (String s : strs) {
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            groups.computeIfAbsent(new String(chars), k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(groups.values());
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.groupAnagrams(
            new String[]{"eat", "tea", "tan", "ate", "nat", "bat"}));
    }
}
