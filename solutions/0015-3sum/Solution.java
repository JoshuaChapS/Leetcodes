import java.util.*;

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> sol = new ArrayList<>();
        Arrays.sort(nums);
        int n = nums.length;
        int i = 0;
        while (i < n - 2) {
            int izq = i + 1, der = n - 1;
            while (izq < der) {
                int total = nums[i] + nums[izq] + nums[der];
                if (total > 0) der--;
                else if (total < 0) izq++;
                else {
                    sol.add(Arrays.asList(nums[i], nums[izq], nums[der]));
                    while (izq < der && nums[izq + 1] == nums[izq]) izq++;
                    izq++;
                }
            }
            while (i < n - 2 && nums[i + 1] == nums[i]) i++;
            i++;
        }
        return sol;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.threeSum(new int[]{-1, 0, 1, 2, -1, -4}));  // [[-1, -1, 2], [-1, 0, 1]]
    }
}
