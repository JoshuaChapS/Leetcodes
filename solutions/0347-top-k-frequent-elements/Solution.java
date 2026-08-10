import java.util.*;

public class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums) count.put(n, count.getOrDefault(n, 0) + 1);

        List<List<Integer>> buckets = new ArrayList<>();
        for (int i = 0; i <= nums.length; i++) buckets.add(new ArrayList<>());
        for (Map.Entry<Integer, Integer> e : count.entrySet())
            buckets.get(e.getValue()).add(e.getKey());

        int[] res = new int[k];
        int idx = 0;
        for (int f = buckets.size() - 1; f > 0; f--) {
            for (int n : buckets.get(f)) {
                res[idx++] = n;
                if (idx == k) return res;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(Arrays.toString(
            sol.topKFrequent(new int[]{1, 1, 1, 2, 2, 3}, 2)));
    }
}
