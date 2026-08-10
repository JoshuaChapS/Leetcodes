import java.util.Arrays;

public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int izq = 0, der = numbers.length - 1;
        while (izq < der && numbers[izq] + numbers[der] != target) {
            if (numbers[izq] + numbers[der] > target) der--;
            else izq++;
        }
        if (izq >= der) return new int[]{};
        return new int[]{izq + 1, der + 1};
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(Arrays.toString(s.twoSum(new int[]{2, 7, 11, 15}, 9))); // [1, 2]
    }
}
