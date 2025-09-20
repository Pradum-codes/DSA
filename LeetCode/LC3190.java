import java.util.Scanner;

class Solution {
    int minimumOperations(int[] nums) {
        int op = 0;
        for(int num : nums) {
            op += Math.min(num%3, 3-(num%3));
        }

        return op;
    }
};

class LC3190 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        Solution sol = new Solution();
        System.out.println(sol.minimumOperations(arr));
        sc.close();
    }
}