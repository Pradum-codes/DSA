import java.util.Scanner;

class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int count = 0;
        
        for (int num : arr) {
            if ((num & 1) != 0) {
                count++;
                if (count == 3) return true;
            } else {
                count = 0;
            }
        }
        
        return false;
    }
}

public class LC1550 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i<n; i++) {
            arr[i] = sc.nextInt();
        }
        Solution sol = new Solution();
        boolean res = sol.threeConsecutiveOdds(arr);
        if(res) {
            System.out.println("TRUE");
        } else {
            System.out.println("FALSE");
        }
        sc.close();
    }
}