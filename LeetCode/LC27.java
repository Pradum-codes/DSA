import java.util.Scanner;
import java.util.Arrays;

class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;
        int j = nums.length - 1;

        while (i <= j) {
            if (nums[i] == val) {
                nums[i] = nums[j];
                j--;
            } else {
                i++;
            }
        }

        return i; 
    }
}

public class LC27 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.print("Enter array size: ");
        int n = sc.nextInt();

        System.out.print("Enter value to remove: ");
        int val = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter array elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int res = sol.removeElement(arr, val);

        System.out.println("New length after removal: " + res);
        System.out.print("Modified array: ");
        System.out.println(Arrays.toString(Arrays.copyOf(arr, res)));

        sc.close();
    }
}
