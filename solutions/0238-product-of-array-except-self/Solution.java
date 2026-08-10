import java.util.*;

public class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        ans[0] = 1;
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];
        int der = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= der;
            der *= nums[i];
        }
        return ans;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(Arrays.toString(
            sol.productExceptSelf(new int[]{1, 2, 3, 4})));
    }
}
